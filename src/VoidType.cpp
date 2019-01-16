#include "VoidType.h"
#include "GenerateContext.h"

using namespace WorkScript;
using namespace std;

VoidType VoidType::type;

std::wstring WorkScript::VoidType::getName() const
{
	return L"void";
}

std::wstring WorkScript::VoidType::getIdentifierString() const
{
	return L"v";
}

TypeClassification WorkScript::VoidType::getClassification() const
{
	return TypeClassification::VOID;
}

llvm::Type * WorkScript::VoidType::getLLVMType(GenerateContext * context) const
{
	llvm::LLVMContext &llvmCtx = *context->getLLVMContext();
	return llvm::Type::getVoidTy(llvmCtx);
}