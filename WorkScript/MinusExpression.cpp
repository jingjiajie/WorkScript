#include "stdafx.h"
#include "MinusExpression.h"
#include "Type.h"
#include "DoubleExpression.h"
#include "StringExpression.h"
#include "VariableExpression.h"
#include "PlusExpression.h"
#include "Program.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

MinusExpression::~MinusExpression()
{
}

ExpressionType MinusExpression::getExpressionType() const
{
	return ExpressionType::MINUS_EXPRESSION;
}

Expression * WorkScript::MinusExpression::clone() const
{
	return new thistype(this->leftExpression, this->rightExpression);
}

std::wstring WorkScript::MinusExpression::getOperatorString() const
{
	return L"-";
}

std::wstring WorkScript::MinusExpression::getOperatorFunctionName() const
{
	return OPERATOR_MINUS_FUNCTION_NAME;
}
