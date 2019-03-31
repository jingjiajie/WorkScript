#include "ReferenceType.h"

using namespace WorkScript;
using namespace std;

#define REF_LLVM_TYPENAME L"@ref"
#define REF_LLVM_MANGLED_TYPENAME L"4@ref"

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
	name += REF_LLVM_MANGLED_TYPENAME;
	return name;
}

TypeClassification ReferenceType::getClassification() const noexcept
{
	return TypeClassification::REFERENCE;
}

llvm::Type * ReferenceType::getLLVMType(GenerateContext * context) const
{
	llvm::Type *targetLLVMType = this->targetType->getLLVMType(context);
	llvm::StructType::get

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
	wstring idStr = ReferenceType::getIdentifierString(targetType);
	auto it = types.find(idStr);
	if (it != types.end())return it->second;
	return (types[idStr] = new ReferenceType(targetType));
}

void WorkScript::ArrayType::releaseTypes() noexcept
{
	for (auto it : types) {
		delete it.second;
	}
}
