#include "stdafx.h"
#include "UnaryOperatorExpression.h"
#include "Type.h"

using namespace WorkScript;

UnaryOperatorExpression::~UnaryOperatorExpression()
{
	delete this->subExpression;
}

bool UnaryOperatorExpression::equals(Expression *target) const
{
	return target == this;
}

std::wstring WorkScript::UnaryOperatorExpression::toString() const
{
	return this->getOperatorString() + this->subExpression->toString();
}

Type * WorkScript::UnaryOperatorExpression::getType() const
{
	Type *subExprType = this->subExpression->getType();
	return subExprType->inferReturnType(this->getOperatorFunctionName(), {});
}
