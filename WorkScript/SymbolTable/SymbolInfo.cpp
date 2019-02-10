#include "SymbolInfo.h"
#include "Type.h"
#include "Locales.h"
#include "Report.h"
#include "Value.h"

WorkScript::SymbolInfo::~SymbolInfo() noexcept
{
	if (this->value)delete this->value;
}

llvm::Value * WorkScript::SymbolInfo::getLLVMValue(const DebugInfo &d, GenerateContext * context)
{
	if (this->llvmValue) {
		return this->llvmValue;
	}
	else {
		auto builder = context->getIRBuilder();
		auto llvmVal = builder->CreateLoad(this->getLLVMValuePtr(d, context));
		this->llvmValue = llvmVal;
		return llvmVal;
	}
}

llvm::Value * WorkScript::SymbolInfo::getLLVMValuePtr(const DebugInfo &d, GenerateContext * context)
{
	if (!this->llvmValuePtr)
	{
		if(this->llvmValue){
			d.getReport()->error(UnassignableError(d, L"变量"+this->name+L"不可赋值！"), ErrorBehavior::CANCEL_EXPRESSION);
		}
		auto builder = context->getIRBuilder();
		this->llvmValuePtr = builder->CreateAlloca(this->type->getLLVMType(context), nullptr, Locales::fromWideChar(Encoding::ANSI, this->name));
	}
	return this->llvmValuePtr;
}

void WorkScript::SymbolInfo::promoteType(Type * targetType)
{
	this->type = Type::getPromotedType(this->debugInfo, this->type, targetType);
}

const WorkScript::DebugInfo &WorkScript::SymbolInfo::getDebugInfo() const noexcept
{
    return debugInfo;
}

void WorkScript::SymbolInfo::setDebugInfo(const WorkScript::DebugInfo &debugInfo) noexcept
{
    this->debugInfo = debugInfo;
}

void WorkScript::SymbolInfo::setValue(WorkScript::Value *value) noexcept
{
	if (this->value) delete this->value;
	this->value = value;
}