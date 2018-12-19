#include "stdafx.h"
#include "SymbolInfo.h"
#include "Type.h"
#include "Locale.h"

llvm::Value * WorkScript::SymbolInfo::getLLVMValue(GenerateContext * context)
{
	auto builder = context->getIRBuilder();
	return builder->CreateLoad(this->getLLVMValuePtr(context));
}

llvm::Value * WorkScript::SymbolInfo::getLLVMValuePtr(GenerateContext * context)
{
	if (!this->llvmValuePtr)
	{
		auto builder = context->getIRBuilder();
		this->llvmValuePtr = builder->CreateAlloca(this->type->getLLVMType(context), nullptr, Locale::unicodeToUTF8(this->name));
	}
	return this->llvmValuePtr;
}

void WorkScript::SymbolInfo::promoteType(Type * targetType)
{
	this->type = Type::getPromotedType(this->type, targetType);
}
