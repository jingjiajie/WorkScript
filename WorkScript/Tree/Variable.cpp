#include "Variable.h"
#include "Type.h"
#include "Utils.h"
#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "InstantialContext.h"
#include "Exception.h"

using namespace std;
using namespace WorkScript;

Variable::Variable(const ExpressionInfo &exprInfo, const std::wstring & name)
	:Expression(exprInfo), name(name) {}

GenerateResult WorkScript::Variable::generateIR(GenerateContext * context)
{
	auto instantialContext = context->getInstantialContext();
	SymbolInfo *symbolInfo = instantialContext->getSymbolInfo(this->name);
	if (!symbolInfo) {
		this->expressionInfo.getDebugInfo().getReport()->error(UndefinedSymbolError(this->expressionInfo.getDebugInfo(), L"无法找到符号：" + this->name));
		throw OperationCanceledException();
	}

	if (context->isLeftValue()) {
		return symbolInfo->getLLVMValuePtr(this->getDebugInfo(), context);
	}
	else {
		return symbolInfo->getLLVMValue(this->getDebugInfo(), context);
	}
}

Type * Variable::getType(InstantialContext *context) const
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
