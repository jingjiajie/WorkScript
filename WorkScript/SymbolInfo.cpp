#include "stdafx.h"
#include "SymbolInfo.h"
#include "Type.h"

llvm::Value * WorkScript::SymbolInfo::getLLVMValue(GenerateContext * context)
{
	if (!this->llvmValue)
	{
		auto builder = context->getIRBuilder();
		this->llvmValue = builder->CreateAlloca(this->type->getLLVMType(context), nullptr, boost::locale::conv::from_utf(this->name, "UTF-8"));
	}
	return this->llvmValue;
}