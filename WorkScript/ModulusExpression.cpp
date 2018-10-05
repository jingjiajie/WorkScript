#include "stdafx.h"
#include "ModulusExpression.h"
#include "Type.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

ModulusExpression::~ModulusExpression()
{
}

ExpressionType ModulusExpression::getExpressionType() const
{
	return ExpressionType::MODULUS_EXPRESSION;
}

Expression * WorkScript::ModulusExpression::clone() const
{
	return new thistype(this->leftExpression, this->rightExpression);
}

std::wstring WorkScript::ModulusExpression::getOperatorString() const
{
	return L"%";
}

std::wstring WorkScript::ModulusExpression::getOperatorFunctionName() const
{
	return OPERATOR_MODULUS_FUNCTION_NAME;
}
