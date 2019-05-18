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

llvm::Value* ReferenceType::getTargetPointer(GenerateContext *context, llvm::Value *pRef) noexcept
{
    auto builder = context->getIRBuilder();
    auto elemPtr = builder->CreateStructGEP(pRef, 0 ,"target");
    return builder->CreateLoad(elemPtr);
}

llvm::Value* ReferenceType::getLocalheapPointer(WorkScript::GenerateContext *context, llvm::Value *pRef) noexcept
{
    auto builder = context->getIRBuilder();
	auto elemPtr = builder->CreateStructGEP(pRef, 1 ,"localheap");
    return builder->CreateLoad(elemPtr);
}

Type* ReferenceType::getTargetType() noexcept
{
    return this->targetType;
}

void ReferenceType::setTargetPointer(GenerateContext *context, llvm::Value *pRef, llvm::Value *target) noexcept
{
    auto builder = context->getIRBuilder();
	auto elemPtr = builder->CreateStructGEP(pRef, 0 ,"target");
	target = builder->CreateBitCast(target, llvm::PointerType::getInt8PtrTy(*context->getLLVMContext(), 0U));
    builder->CreateStore(target, elemPtr);
}

void ReferenceType::setLocalheapPointer(GenerateContext *context, llvm::Value *pRef, llvm::Value *localheap) noexcept
{
    auto builder = context->getIRBuilder();
	auto elemPtr = builder->CreateStructGEP(pRef, 1 ,"localheap");
	localheap = builder->CreateBitCast(localheap, llvm::PointerType::getInt8PtrTy(*context->getLLVMContext(), 0U));
    builder->CreateStore(localheap, elemPtr);
}