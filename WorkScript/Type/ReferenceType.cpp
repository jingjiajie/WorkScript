#include "ReferenceType.h"
#include "GenerateContext.h"

using namespace WorkScript;
using namespace std;

std::unordered_map<std::wstring, ReferenceType*> ReferenceType::types;
Finalizer ReferenceType::staticFinalizer(&ReferenceType::releaseTypes);


std::wstring WorkScript::ReferenceType::getName() const noexcept
{
	wstring name = L"[" + this->targetType->getName() + L"]";
	return name;
}

std::wstring ReferenceType::getMangledName() const noexcept
{
	return ReferenceType::getMangledName(this->targetType);
}

std::wstring ReferenceType::getMangledName(Type * targetType) noexcept
{
	wstring name = targetType->getMangledName();
	name += L"4@ref";
	return name;
}

TypeClassification ReferenceType::getClassification() const noexcept
{
	return TypeClassification::REFERENCE;
}

llvm::Type * ReferenceType::getLLVMType(GenerateContext * context) const
{
    static llvm::StructType *type = nullptr;
    if(!type) {
        llvm::LLVMContext &llvmCtx = *context->getLLVMContext();
        type = llvm::StructType::create(llvmCtx, {llvm::Type::getInt8PtrTy(llvmCtx),   //目标指针
                                               llvm::Type::getInt8PtrTy(llvmCtx)}, "@ref"); //局部堆地址
    }
    return type;
}

bool ReferenceType::equals(const Type * type) const noexcept
{
	if(type->getClassification() != TypeClassification::REFERENCE) return false;
	const ReferenceType *target = (const ReferenceType*)type;
	if (!this->targetType->equals(target->targetType))return false;
	return true;
}

ReferenceType * ReferenceType::get(Type * targetType) noexcept
{
	wstring idStr = ReferenceType::getMangledName(targetType);
	auto it = types.find(idStr);
	if (it != types.end())return it->second;
	return (types[idStr] = new ReferenceType(targetType));
}

void WorkScript::ReferenceType::releaseTypes() noexcept
{
	for (auto it : types) {
		delete it.second;
	}
}

llvm::Value* ReferenceType::getTargetPointer(GenerateContext *context, llvm::Value *ref) noexcept
{
    auto builder = context->getIRBuilder();
    return builder->CreateExtractValue(ref, 0, "target");
}

llvm::Value* ReferenceType::getLocalheapPointer(WorkScript::GenerateContext *context, llvm::Value *ref) noexcept
{
    auto builder = context->getIRBuilder();
    return builder->CreateExtractValue(ref, 1, "localheap");
}

Type* ReferenceType::getTargetType() noexcept
{
    return this->targetType;
}

void ReferenceType::setTargetPointer(GenerateContext *context, llvm::Value *ref, llvm::Value *target) noexcept
{
    auto builder = context->getIRBuilder();
    builder->CreateInsertValue(ref, target, 0, "target");
}

void ReferenceType::setLocalheapPointer(GenerateContext *context, llvm::Value *ref, llvm::Value *localheap) noexcept
{
    auto builder = context->getIRBuilder();
    builder->CreateInsertValue(ref, localheap, 1, "localheap");
}