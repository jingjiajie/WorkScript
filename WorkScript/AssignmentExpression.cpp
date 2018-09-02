#include "AssignmentExpression.h"
#include "StringExpression.h"
#include "Context.h"
#include "UnassignableExpection.h"
#include "ExpressionPointerExpression.h"
#include "VariableExpression.h"

#include <boost/locale.hpp>
#include <string>

AssignmentExpression::~AssignmentExpression()
{
	
}

const Pointer<Expression> AssignmentExpression::evaluate(Context * const & context)
{
	context->setAssignLeft(true);
	Pointer<Expression> evaluatedLeft  = this->leftExpression->evaluate(context);

	context->setAssignLeft(false);
	if (!evaluatedLeft->getType(context)->equals(context, TypeExpression::EXPRESSION_POINTER_EXPRESSION))
	{
		Pointer<StringExpression> leftStr  =  evaluatedLeft->toString(context);
		UnassignableExpection ex(leftStr->getValue());
		context->release();
		throw std::move(ex);
	}
	auto leftPointer = (const Pointer<ExpressionPointerExpression>)evaluatedLeft;
	auto evaluatedRight = this->rightExpression->evaluate(context);
	leftPointer->setTargetValue(evaluatedRight);
	return evaluatedRight;
}

const Pointer<TypeExpression> AssignmentExpression::getType(Context * const & context) const
{
	return TypeExpression::ASSIGNMENT_EXPRESSION;
}

const Pointer<StringExpression> AssignmentExpression::toString(Context * const & context)
{
	static Pointer<StringExpression> assign(new StringExpression(L" = ", ReleaseStrategy::DELETE));
	return BinaryOperatorExpression::toString(context, assign);
}

const Pointer<AssignmentExpression> AssignmentExpression::evaluateParamAssignment(Context * const & context)
{
	auto leftVar = this->leftExpression;
	auto evaluatedRight = this->rightExpression->evaluate(context);
	auto newMe = new AssignmentExpression(leftVar,evaluatedRight);
	return newMe;
}
