#include "stdafx.h"
#include "VariableExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "Utils.h"
#include "SymbolTable.h"
#include "SymbolInfo.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::VariableExpression::generateIR(GenerateContext * context)
{
	return symbolInfo->getLLVMValue(context);
}

Type * VariableExpression::getType() const
{
	return symbolInfo->getType();
}

Expression * WorkScript::VariableExpression::clone() const
{
	auto newInstance = new thistype(program, symbolInfo);
	newInstance->varargs = this->varargs;
	return newInstance;
}

std::wstring VariableExpression::toString() const
{
	return this->symbolInfo->getName();
}

ExpressionType VariableExpression::getExpressionType() const
{
	return ExpressionType::VARIABLE_EXPRESSION;
}
