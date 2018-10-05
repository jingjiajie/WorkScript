#include "stdafx.h"
#include "PlusExpression.h"
#include "Type.h"
#include "DoubleExpression.h"
#include "StringExpression.h"
#include "MemberEvaluateExpression.h"
#include "VariableExpression.h"
#include "MinusExpression.h"
#include "Program.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

PlusExpression::~PlusExpression()
{
}

ExpressionType PlusExpression::getExpressionType() const
{
	return ExpressionType::PLUS_EXPRESSION;
}

Expression * WorkScript::PlusExpression::clone() const
{
	return new thistype(this->leftExpression,this->rightExpression);
}

std::wstring WorkScript::PlusExpression::getOperatorString() const
{
	return L"+";
}

std::wstring WorkScript::PlusExpression::getOperatorFunctionName() const
{
	return OPERATOR_PLUS_FUNCTION_NAME;
}
