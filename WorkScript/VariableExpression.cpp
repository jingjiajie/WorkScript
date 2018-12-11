#include "stdafx.h"
#include "VariableExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "LinkException.h"
#include "Utils.h"
#include "SymbolInfo.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::VariableExpression::generateIR(GenerateContext * context)
{
	auto symbolInfo = this->symbolTable->getSymbolInfo(this->name);
	llvm::Value *var = ((SymbolInfo*)symbolInfo)->getLLVMValue(context);
	return var;
}

Type * VariableExpression::getType() const
{
	const SymbolInfo *info = this->symbolTable->getSymbolInfo(this->name);
	return (Type*)info->getType();
}

//bool VariableExpression::equals(Expression * targetExpression) const
//{
//	return targetExpression == this;
//}

Expression * WorkScript::VariableExpression::clone() const
{
	auto newInstance = new thistype(this->name);
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
