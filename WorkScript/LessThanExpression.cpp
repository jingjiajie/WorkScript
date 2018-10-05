#include "stdafx.h"
#include "LessThanExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "DoubleExpression.h"
#include "Utils.h"

using namespace WorkScript;
using namespace std;

LessThanExpression::~LessThanExpression()
{
}

ExpressionType LessThanExpression::getExpressionType() const
{
	return ExpressionType::LESS_THAN_EXPRESSION;
}

Expression * WorkScript::LessThanExpression::clone() const
{
	return new thistype(this->leftExpression, this->rightExpression);
}

std::wstring WorkScript::LessThanExpression::getOperatorString() const
{
	return L"<";
}

std::wstring WorkScript::LessThanExpression::getOperatorFunctionName() const
{
	return OPERATOR_LESS_THAN_FUNCTION_NAME;
}