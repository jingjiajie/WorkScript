#include "stdafx.h"
#include "VoidType.h"
#include "GenerateContext.h"

using namespace WorkScript;
using namespace std;

TypeClassification WorkScript::VoidType::getClassification() const
{
	return TypeClassification::VOID;
}

llvm::Type * WorkScript::VoidType::getLLVMType(GenerateContext * context) const
{
	llvm::LLVMContext &llvmCtx = *context->getLLVMContext();
	return llvm::Type::getVoidTy(llvmCtx);
}