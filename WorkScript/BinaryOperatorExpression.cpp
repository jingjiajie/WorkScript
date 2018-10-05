#include "stdafx.h"
#include "BinaryOperatorExpression.h"
#include "Type.h"
#include "Function.h"

using namespace std;
using namespace WorkScript;

BinaryOperatorExpression::~BinaryOperatorExpression()
{
	delete this->leftExpression;
	delete this->rightExpression;
}

GenerateResult WorkScript::BinaryOperatorExpression::generateIR(GenerateContext * context)
{
	Type *leftType = this->leftExpression->getType();
	Type *rightType = this->rightExpression->getType();
	Function *func = leftType->getMemberFunction(this->getOperatorFunctionName());
	Overload *overload = func->getOverload({ rightType });
}

std::wstring WorkScript::BinaryOperatorExpression::toString() const
{
	auto left = this->leftExpression->toString();
	auto right = this->rightExpression->toString();
	return left + this->getOperatorString() + right;
}

Type * WorkScript::BinaryOperatorExpression::getType() const
{
	Type *leftType = this->leftExpression->getType();
	Type *rightType = this->rightExpression->getType();
	return leftType->inferReturnType(this->getOperatorFunctionName(), { rightType });
}
