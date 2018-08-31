#include "AssignmentExpression.h"
#include "StringExpression.h"
#include "Context.h"
#include "UnassignableExpection.h"
#include "ExpressionPointerExpression.h"
#include "TempExpression.h"
#include "VariableExpression.h"

#include <boost/locale.hpp>
#include <string>

AssignmentExpression::~AssignmentExpression()
{
	
}

Expression * const AssignmentExpression::evaluate(Context * const & context)
{
	context->setAssignLeft(true);
	TempExpression<Expression> evaluatedLeft(this->leftExpression, this->leftExpression->evaluate(context));

	context->setAssignLeft(false);
	if (!evaluatedLeft->getType(context)->equals(context, &TypeExpression::EXPRESSION_POINTER_EXPRESSION))
	{
		TempExpression<StringExpression> leftStr(evaluatedLeft, evaluatedLeft->toString(context));
		UnassignableExpection ex(leftStr->getValue());
		context->release();
		throw std::move(ex);
	}
	auto leftPointer = (ExpressionPointerExpression *const)evaluatedLeft.getExpression();
	auto evaluatedRight = this->rightExpression->evaluate(context);
	//如果右值级别小于LOCAL，则提升为LOCAL
	if (evaluatedRight->getStorageLevel() < StorageLevel::LOCAL) {
		evaluatedRight->setStorageLevel(StorageLevel::LOCAL);
	}
	else if (evaluatedRight->getStorageLevel() == StorageLevel::LOCAL) {
		evaluatedRight->setStorageLevel(StorageLevel::EXTERN);
	}
	leftPointer->setTargetValue(evaluatedRight);
	return evaluatedRight;
}

TypeExpression * const AssignmentExpression::getType(Context * const & context) const
{
	return &TypeExpression::ASSIGNMENT_EXPRESSION;
}

StringExpression * const AssignmentExpression::toString(Context * const & context)
{
	static StringExpression assign(L" = ", StorageLevel::EXTERN);
	return BinaryOperatorExpression::toString(context, &assign);
}

AssignmentExpression * const AssignmentExpression::evaluateParamAssignment(Context * const & context)
{
	auto leftVar = (VariableExpression *const)this->leftExpression;
	auto evaluatedRight = this->rightExpression->evaluate(context);
	auto newMe = new AssignmentExpression(leftVar,evaluatedRight);
	return newMe;
}
