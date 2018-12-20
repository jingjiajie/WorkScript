#include "stdafx.h"
#include "TemplateVariable.h"
#include "Type.h"
#include "VariableExpression.h"
#include "InstantializeContext.h"
#include "WorkScriptException.h"

using namespace WorkScript;
using namespace std;

inline WorkScript::TemplateVariableExpression::TemplateVariableExpression(const ExpressionInfo &exprInfo, const std::wstring & name, SymbolTable * symbolTable, Type * type)
	:Expression(exprInfo), bindSymbolTable(symbolTable), name(name)
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

Expression * WorkScript::TemplateVariableExpression::instantialize(InstantializeContext *context)
{
	SymbolTable *targetSymbolTable = context->getCurrentSymbolTable();
	SymbolInfo *mySymbolInfo = this->bindSymbolTable->getSymbolInfo(name);
	return new VariableExpression(expressionInfo, name, targetSymbolTable, mySymbolInfo->getType());
}

GenerateResult WorkScript::TemplateVariableExpression::generateIR(GenerateContext * context)
{
	throw WorkScriptException(L"模板变量不可以生成IR，需要先实例化");
}

Type * WorkScript::TemplateVariableExpression::getType() const
{
	SymbolInfo *mySymbolInfo = this->bindSymbolTable->getSymbolInfo(this->name);
	return mySymbolInfo->getType();
}

Expression * WorkScript::TemplateVariableExpression::clone() const
{
	return new TemplateVariableExpression(expressionInfo, this->name, bindSymbolTable);
}

std::wstring WorkScript::TemplateVariableExpression::toString() const
{
	return this->name;
}

ExpressionType WorkScript::TemplateVariableExpression::getExpressionType() const
{
	return ExpressionType::TEMPLATE_CALL_EXPRESSION;
}

void WorkScript::TemplateVariableExpression::promoteType(Type * type)
{
	SymbolInfo *mySymbolInfo = this->bindSymbolTable->getSymbolInfo(this->name);
	mySymbolInfo->promoteType(type);
}
