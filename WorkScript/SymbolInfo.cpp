#include "stdafx.h"
#include "SymbolInfo.h"
#include "Type.h"

llvm::Value * WorkScript::SymbolInfo::getLLVMValue(GenerateContext * context) const
{
	if (!this->llvmValue)
	{
		auto builder = context->getIRBuilder();
		this->llvmValue = builder->CreateAlloca(this->type->getLLVMType(), nullptr, boost::locale::conv::from_utf(this->name, "UTF-8"));
	}
	return this->llvmValue;
}