#include "stdafx.h"
#include "DivideExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "Program.h"
#include "VariableExpression.h"
#include "MultiplyExpression.h"
#include "IntegerExpression.h"
#include "FloatExpression.h"
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

GenerateResult WorkScript::DivideExpression::generateLLVMIRIntegerInteger(GenerateContext * context, IntegerExpression * left, IntegerExpression * right) const
{
	return GenerateResult();
}

GenerateResult WorkScript::DivideExpression::generateLLVMIRIntegerFloat(GenerateContext * context, IntegerExpression * left, FloatExpression * right) const
{
	return GenerateResult();
}

GenerateResult WorkScript::DivideExpression::generateLLVMIRFloatInteger(GenerateContext * context, FloatExpression * left, IntegerExpression * right) const
{
	return GenerateResult();
}

GenerateResult WorkScript::DivideExpression::generateLLVMIRFloatFloat(GenerateContext * context, FloatExpression * left, FloatExpression * right) const
{
	return GenerateResult();
}
