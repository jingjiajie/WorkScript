#include "VoidType.h"
#include "GenerateContext.h"

using namespace WorkScript;
using namespace std;

VoidType VoidType::type;

std::wstring WorkScript::VoidType::getName() const noexcept
{
	return L"void";
}

std::wstring WorkScript::VoidType::getIdentifierString() const noexcept
{
	return L"v";
}

TypeClassification WorkScript::VoidType::getClassification() const noexcept
{
	return TypeClassification::VOID;
}

llvm::Type * WorkScript::VoidType::getLLVMType(GenerateContext * context) const
{
	llvm::LLVMContext &llvmCtx = *context->getLLVMContext();
	return llvm::Type::getVoidTy(llvmCtx);
}

bool VoidType::equals(const Type *type) const noexcept
{
    return type->getClassification() == TypeClassification::VOID;
}
