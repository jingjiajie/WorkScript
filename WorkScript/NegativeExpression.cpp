#include "stdafx.h"
#include "NegativeExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "DoubleExpression.h"
#include "UncalculatableException.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

ExpressionType NegativeExpression::getExpressionType() const
{
	return ExpressionType::NEGATIVE_EXPRESSION;
}

Expression * WorkScript::NegativeExpression::clone() const
{
	return new thistype(this->subExpression);
}

std::wstring WorkScript::NegativeExpression::getOperatorString() const
{
	return L"-";
}

std::wstring WorkScript::NegativeExpression::getOperatorFunctionName() const
{
	return OPERATOR_NEGATE_FUNCTION_NAME;
}
