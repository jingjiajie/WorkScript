#include "stdafx.h"
#include "MultiplyExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "DoubleExpression.h"
#include "VariableExpression.h"
#include "DivideExpression.h"
#include "Program.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

MultiplyExpression::~MultiplyExpression()
{
}

ExpressionType MultiplyExpression::getExpressionType() const
{
	return ExpressionType::MULTIPLY_EXPRESSION;
}

Expression * WorkScript::MultiplyExpression::clone() const
{
	return new thistype(this->leftExpression, this->rightExpression);
}

std::wstring WorkScript::MultiplyExpression::getOperatorString() const
{
	return L"*";
}

std::wstring WorkScript::MultiplyExpression::getOperatorFunctionName() const
{
	return OPERATOR_MULTIPLY_FUNCTION_NAME;
}