#include "stdafx.h"
#include "LessThanEqualExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "DoubleExpression.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

LessThanEqualExpression::~LessThanEqualExpression()
{
}

ExpressionType LessThanEqualExpression::getExpressionType() const
{
	return ExpressionType::LESS_THAN_EQUAL_EXPRESSION;
}

Expression * WorkScript::LessThanEqualExpression::clone() const
{
	return new thistype(this->leftExpression, this->rightExpression);
}

std::wstring WorkScript::LessThanEqualExpression::getOperatorString() const
{
	return L"<=";
}

std::wstring WorkScript::LessThanEqualExpression::getOperatorFunctionName() const
{
	return OPERATOR_LESS_THAN_EQUAL_FUNCTION_NAME;
}