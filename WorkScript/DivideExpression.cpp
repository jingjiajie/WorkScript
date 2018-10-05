#include "stdafx.h"
#include "DivideExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "DoubleExpression.h"
#include "Program.h"
#include "VariableExpression.h"
#include "MultiplyExpression.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

ExpressionType DivideExpression::getExpressionType() const
{
	return ExpressionType::DIVIDE_EXPRESSION;
}

Expression * WorkScript::DivideExpression::clone() const
{
	return new thistype(this->leftExpression, this->rightExpression);
}

std::wstring WorkScript::DivideExpression::getOperatorString() const
{
	return L"/";
}

std::wstring WorkScript::DivideExpression::getOperatorFunctionName() const
{
	return OPERATOR_DIVIDE_FUNCTION_NAME;
}
