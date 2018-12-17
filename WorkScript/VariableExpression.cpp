#include "stdafx.h"
#include "VariableExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "Utils.h"
#include "SymbolTable.h"
#include "SymbolInfo.h"

using namespace std;
using namespace WorkScript;

void WorkScript::VariableExpression::bindSymbols()
{
	SymbolInfo *symbolInfo = this->program->getSymbolTable()->getSymbolInfo(this->name);
	if (!symbolInfo) {
		throw WorkScriptException(L"ÎÞ·¨ÕÒµ½·ûºÅ£º" + symbolInfo->getName());
	}
	this->bindSymbolInfo = symbolInfo;
}

GenerateResult WorkScript::VariableExpression::generateIR(GenerateContext * context)
{
	SymbolTable *table = context->getCurrentSymbolTable();
	SymbolInfo *symbolInfo = table->getSymbolInfo(this->name);
	return symbolInfo->getLLVMValue(context);
}

Type * VariableExpression::getType() const
{
	return type;
}

Expression * WorkScript::VariableExpression::clone() const
{
	auto newInstance = new thistype(EXPRESSION_MEMBERS, name, type);
	newInstance->varargs = this->varargs;
	return newInstance;
}

std::wstring VariableExpression::toString() const
{
	return this->name;
}

ExpressionType VariableExpression::getExpressionType() const
{
	return ExpressionType::VARIABLE_EXPRESSION;
}
