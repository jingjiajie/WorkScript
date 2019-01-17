#include "Variable.h"
#include "Type.h"
#include "Utils.h"
#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "InstantializeContext.h"

using namespace std;
using namespace WorkScript;

Variable::Variable(const ExpressionInfo &exprInfo, const std::wstring & name)
	:Expression(exprInfo), name(name) {}

GenerateResult WorkScript::Variable::generateIR(GenerateContext * context)
{
	auto instantializeContext = context->getInstantializeContext();
	SymbolInfo *symbolInfo = instantializeContext->getSymbolInfo(this->name);
	if (!symbolInfo) {
		throw WorkScriptException(this->expressionInfo.getLocation(), L"无法找到符号：" + this->name);
	}

	if (context->isLeftValue()) {
		return symbolInfo->getLLVMValuePtr(context);
	}
	else {
		return symbolInfo->getLLVMValue(context);
	}
}

Type * Variable::getType(InstantializeContext *context) const
{
	SymbolInfo *symbolInfo = context->getSymbolInfo(this->name);
	if (!symbolInfo)return nullptr;
	return symbolInfo->getType();
}

Expression * WorkScript::Variable::clone() const
{
	auto newInstance = new thistype(expressionInfo, name);
	newInstance->varargs = this->varargs;
	newInstance->declarable = declarable;
	return newInstance;
}

std::wstring Variable::toString() const
{
	return this->name;
}

ExpressionType Variable::getExpressionType() const
{
	return ExpressionType::VARIABLE_EXPRESSION;
}
