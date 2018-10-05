#include "stdafx.h"
#include "AssignmentExpression.h"
#include "StringExpression.h"
#include "UnassignableExpection.h"
#include "VariableExpression.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

ExpressionType AssignmentExpression::getExpressionType() const
{
	return ExpressionType::ASSIGNMENT_EXPRESSION;
}

Expression * WorkScript::AssignmentExpression::clone() const
{
	return new thistype(this->leftExpression, this->rightExpression);
}

std::wstring WorkScript::AssignmentExpression::getOperatorString() const
{
	return L":=";
}

std::wstring WorkScript::AssignmentExpression::getOperatorFunctionName() const
{
	return OPERATOR_ASSIGN_FUNCTION_NAME;
}
