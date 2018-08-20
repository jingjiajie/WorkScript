#include "AssignmentExpression.h"
#include "StringExpression.h"
#include "Context.h"
#include "UnassignableExpection.h"
#include "PointerExpression.h"
#include "TempExpression.h"

#include <string>

AssignmentExpression::~AssignmentExpression()
{
	
}

Expression * const AssignmentExpression::evaluate(Context * const & context)
{
	context->setAssignLeft(true);
	TempExpression<Expression> evaluatedLeft(this->leftExpression, this->leftExpression->evaluate(context));

	context->setAssignLeft(false);
	if (!evaluatedLeft->getType(context)->equals(context, &TypeExpression::POINTER_EXPRESSION))
	{
		TempExpression<StringExpression> leftStr(evaluatedLeft, evaluatedLeft->toString(context));
		UnassignableExpection ex(leftStr->getValue());
		context->release();
		throw std::move(ex);
	}
	auto leftPointer = (const PointerExpression *const)evaluatedLeft.getExpression();
	auto evaluatedRight = this->rightExpression->evaluate(context);
	//如果右值级别小于LOCAL，则提升为LOCAL
	if (evaluatedRight->getStorageLevel() < StorageLevel::LOCAL) {
		evaluatedRight->setStorageLevel(StorageLevel::LOCAL);
	}
	else if (evaluatedRight->getStorageLevel() == StorageLevel::LOCAL) {
		evaluatedRight->setStorageLevel(StorageLevel::EXTERN);
	}
	leftPointer->getTargetContext()->setLocalVariable(leftPointer->getOffset(), evaluatedRight);
	return evaluatedRight;
}

TypeExpression * const AssignmentExpression::getType(Context * const & context) const
{
	return &TypeExpression::ASSIGNMENT_EXPRESSION;
}

StringExpression * const AssignmentExpression::toString(Context * const & context)
{
	static StringExpression assign(" = ", StorageLevel::EXTERN);
	return BinaryTermExpression::toString(context, &assign);
}
