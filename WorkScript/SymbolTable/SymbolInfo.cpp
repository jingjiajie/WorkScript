#include "SymbolInfo.h"
#include "Type.h"
#include "Locales.h"
#include "WorkScriptException.h"
#include "Constant.h"

WorkScript::SymbolInfo::~SymbolInfo()
{
	if (this->value)delete this->value;
}

llvm::Value * WorkScript::SymbolInfo::getLLVMValue(GenerateContext * context)
{
	if (this->llvmValue) {
		return this->llvmValue;
	}
	else {
		auto builder = context->getIRBuilder();
		auto llvmVal = builder->CreateLoad(this->getLLVMValuePtr(context));
		this->llvmValue = llvmVal;
		return llvmVal;
	}
}

llvm::Value * WorkScript::SymbolInfo::getLLVMValuePtr(GenerateContext * context)
{
	if (!this->llvmValuePtr)
	{
		if(this->llvmValue){
			//TODO Location信息
			throw WorkScriptException(DebugInfo(), L"变量"+this->name+L"不可赋值！");
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

const WorkScript::DebugInfo &WorkScript::SymbolInfo::getDebugInfo() const
{
    return debugInfo;
}

void WorkScript::SymbolInfo::setDebugInfo(const WorkScript::DebugInfo &debugInfo)
{
    this->debugInfo = debugInfo;
}
