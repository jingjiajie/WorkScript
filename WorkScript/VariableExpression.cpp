#include "stdafx.h"
#include "VariableExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "LinkException.h"
#include "Utils.h"
#include "SymbolTable.h"
#include "SymbolInfo.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::VariableExpression::generateIR(GenerateContext * context)
{
	SymbolTable *symbolTable = this->program->getSymbolTable();
	auto symbolInfo = symbolTable->getSymbolInfo(this->name);
	llvm::Value *var = ((SymbolInfo*)symbolInfo)->getLLVMValue(context);
	return var;
}

Type * VariableExpression::getType() const
{
	SymbolTable *symbolTable = this->program->getSymbolTable();
	const SymbolInfo *info = symbolTable->getSymbolInfo(this->name);
	return (Type*)info->getType();
}

Expression * WorkScript::VariableExpression::clone() const
{
	auto newInstance = new thistype(program, this->name);
	newInstance->type = this->type;
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
