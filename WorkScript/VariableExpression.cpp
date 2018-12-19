#include "stdafx.h"
#include "VariableExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "Utils.h"
#include "SymbolTable.h"
#include "SymbolInfo.h"

using namespace std;
using namespace WorkScript;

inline WorkScript::VariableExpression::VariableExpression(EXPRESSION_CTOR_FORMAL_PARAMS, const std::wstring & name, SymbolTable * symbolTable, Type *type)
	:EXPRESSION_CTOR_CALL, bindSymbolTable(symbolTable), name(name) 
{
	SymbolInfo *symbolInfo = symbolTable->getSymbolInfo(name);
	if (!symbolInfo) {
		symbolTable->setSymbol(name, type);
	}
	else {
		if (type && !symbolInfo->getType()->equals(type)) {
			throw WorkScriptException(L"类型推导不符：" + type->getName() + L"和" + symbolInfo->getType()->getName());
		}
	}
}

GenerateResult WorkScript::VariableExpression::generateIR(GenerateContext * context)
{
	SymbolInfo *symbolInfo = this->bindSymbolTable->getSymbolInfo(name);
	if (context->isLeftValue()) {
		return symbolInfo->getLLVMValuePtr(context);
	}
	else {
		return symbolInfo->getLLVMValue(context);
	}
}

Type * VariableExpression::getType() const
{
	SymbolInfo *symbolInfo = this->bindSymbolTable->getSymbolInfo(name);
	return symbolInfo->getType();
}

Expression * WorkScript::VariableExpression::clone() const
{
	SymbolInfo *symbolInfo = this->bindSymbolTable->getSymbolInfo(name);
	auto newInstance = new thistype(EXPRESSION_MEMBERS, name, bindSymbolTable, symbolInfo->getType());
	newInstance->varargs = this->varargs;
	newInstance->declarable = declarable;
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
