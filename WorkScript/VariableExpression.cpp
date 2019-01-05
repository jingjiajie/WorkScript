#include "stdafx.h"
#include "VariableExpression.h"
#include "Type.h"
#include "Utils.h"
#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "InstantializeContext.h"

using namespace std;
using namespace WorkScript;

inline WorkScript::VariableExpression::VariableExpression(const ExpressionInfo &exprInfo, const std::wstring & name)
	:Expression(exprInfo), name(name) {}

GenerateResult WorkScript::VariableExpression::generateIR(GenerateContext * context)
{
	auto instantializeContext = context->getInstantializeContext();
	SymbolInfo *symbolInfo = instantializeContext->getSymbolInfo(this->name);
	if (!symbolInfo) {
		throw WorkScriptException(this->expressionInfo.getLocation(), L"ÎÞ·¨ÕÒµ½·ûºÅ£º" + this->name);
	}

	if (context->isLeftValue()) {
		return symbolInfo->getLLVMValuePtr(context);
	}
	else {
		return symbolInfo->getLLVMValue(context);
	}
}

Type * VariableExpression::getType(InstantializeContext *context) const
{
	SymbolInfo *symbolInfo = context->getSymbolInfo(this->name);
	if (!symbolInfo)return nullptr;
	return symbolInfo->getType();
}

Expression * WorkScript::VariableExpression::clone() const
{
	auto newInstance = new thistype(expressionInfo, name);
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
