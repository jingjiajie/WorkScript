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
	:Value(exprInfo), name(name) {}

GenerateResult WorkScript::Variable::generateIR(GenerateContext * context)
{
	SymbolInfo *symbolInfo = context->getSymbolInfo(this->name);
	if (!symbolInfo) {
		this->expressionInfo.getDebugInfo().getReport()->error(UndefinedSymbolError(this->expressionInfo.getDebugInfo(), L"无法找到符号：" + this->name), ErrorBehavior::CANCEL_EXPRESSION);
	}else {
		vector<ValueDescriptor> descs = symbolInfo->deduce(context).getValueDescriptors();
		vector<llvm::Value*> llvmVals;
		llvmVals.reserve(descs.size());
		for(ValueDescriptor &desc : descs){
		    llvmVals.push_back(desc.getLLVMValue(this->getDebugInfo(), context));
		}
		return llvmVals;
	}
}

DeducedInfo Variable::deduce(InstantialContext *context) const
{
	SymbolInfo *symbolInfo = context->getSymbolInfo(this->name);
	if (!symbolInfo)return ValueDescriptor(nullptr, ValueKind::VARIABLE);
	return symbolInfo->deduce(context);
}

Expression * WorkScript::Variable::clone() const
{
	auto newInstance = new thistype(expressionInfo, name);
	newInstance->declarable = declarable;
	return newInstance;
}

std::wstring Variable::toString() const
{
	return this->name;
}

ExpressionType Variable::getExpressionType() const
{
	return ExpressionType::VARIABLE;
}

//const Value *Variable::getValue(InstantialContext *ctx) const noexcept
//{
//	return const_cast<Variable*>(this)->getValue(ctx);
//}
//
//Value *Variable::getValue(InstantialContext *ctx) noexcept
//{
//	SymbolInfo *info = ctx->getSymbolInfo(this->name);
//	return info->getValue();
//}
