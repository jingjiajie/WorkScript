#include "stdafx.h"
#include "EqualsExpression.h"
#include "Type.h"
#include "BooleanExpression.h"
#include "Program.h"
#include "StringExpression.h"
#include "DoubleExpression.h"
#include "Utils.h"

using namespace WorkScript;
using namespace std;

EqualsExpression::~EqualsExpression()
{
}

Expression * WorkScript::EqualsExpression::clone() const
{
	return new thistype(this->leftExpression, this->rightExpression);
}

ExpressionType EqualsExpression::getExpressionType() const
{
	return ExpressionType::EQUALS_EXPRESSION;
}

std::wstring WorkScript::EqualsExpression::getOperatorString() const
{
	return L"==";
}

std::wstring WorkScript::EqualsExpression::getOperatorFunctionName() const
{
	return OPERATOR_EQUALS_FUNCTION_NAME;
}
