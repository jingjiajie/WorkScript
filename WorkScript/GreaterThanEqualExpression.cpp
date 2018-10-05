#include "stdafx.h"
#include "GreaterThanEqualExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "DoubleExpression.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

GreaterThanEqualExpression::~GreaterThanEqualExpression()
{
}

ExpressionType GreaterThanEqualExpression::getExpressionType() const
{
	return ExpressionType::GREATER_THAN_EQUAL_EXPRESSION;
}

Expression * WorkScript::GreaterThanEqualExpression::clone() const
{
	return new thistype(this->leftExpression, this->rightExpression);
}

std::wstring WorkScript::GreaterThanEqualExpression::getOperatorString() const
{
	return L">=";
}

std::wstring WorkScript::GreaterThanEqualExpression::getOperatorFunctionName() const
{
	return OPERATOR_GREATER_THAN_EQUAL_FUNCTION_NAME;
}