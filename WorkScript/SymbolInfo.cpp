#include "stdafx.h"
#include "SymbolInfo.h"
#include "Type.h"
#include "Locale.h"

llvm::Value * WorkScript::SymbolInfo::getLLVMValue(GenerateContext * context)
{
	if (!this->llvmValue)
	{
		auto builder = context->getIRBuilder();
		this->llvmValue = builder->CreateAlloca(this->type->getLLVMType(context), nullptr,Locale::unicodeToUTF8(this->name));
	}
	return this->llvmValue;
}