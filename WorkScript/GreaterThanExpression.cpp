#include "stdafx.h"
#include "GreaterThanExpression.h"
#include "StringExpression.h"
#include "Program.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

GreaterThanExpression::~GreaterThanExpression()
{
}

ExpressionType GreaterThanExpression::getExpressionType() const
{
	return ExpressionType::GREATER_THAN_EXPRESSION;
}

Expression * WorkScript::GreaterThanExpression::clone() const
{
	return new thistype(this->leftExpression, this->rightExpression);
}

std::wstring WorkScript::GreaterThanExpression::getOperatorString() const
{
	return L"<";
}

std::wstring WorkScript::GreaterThanExpression::getOperatorFunctionName() const
{
	return OPERATOR_GREATER_THAN_FUNCTION_NAME;
}