#include <unordered_map>
#include "ArrayType.h"
#include "TypeClassification.h"

using namespace WorkScript;
using namespace std;

std::unordered_map<std::wstring, ArrayType*> ArrayType::types;
Finalizer ArrayType::staticFinalizer(&ArrayType::releaseTypes);



WorkScript::ArrayType::ArrayType(Type * targetType, const std::vector<size_t>& lenOfEachDimension)
	:Type(false, false), targetType(targetType), lengthOfEachDimension(lenOfEachDimension)
{
}

std::wstring WorkScript::ArrayType::getName() const
{
	wstring name = this->targetType->getName();
	for (size_t i = 0; i < this->lengthOfEachDimension.size(); ++i) {
		name += L"[" + to_wstring(this->lengthOfEachDimension[i]) + L"]";
	}
	return name;
}

std::wstring WorkScript::ArrayType::getIdentifierString() const
{
	return ArrayType::getIdentifierString(this->targetType, this->lengthOfEachDimension);
}

std::wstring WorkScript::ArrayType::getIdentifierString(Type * targetType, const std::vector<size_t>& lenOfEachDimension)
{
	wstring name = targetType->getIdentifierString();
	for (size_t i = 0; i < lenOfEachDimension.size(); ++i) {
		name += L"[" + to_wstring(lenOfEachDimension[i]) + L"]";
	}
	return name;
}

TypeClassification WorkScript::ArrayType::getClassification() const
{
	return TypeClassification::ARRAY;
}

llvm::Type * WorkScript::ArrayType::getLLVMType(GenerateContext * context) const
{
	llvm::Type *type = this->targetType->getLLVMType(context);
	size_t dimensions = this->lengthOfEachDimension.size();
	for (size_t i = 0; i < dimensions; ++i) {
		type = llvm::ArrayType::get(type, this->lengthOfEachDimension[dimensions - i - 1]);
	}
	return type;
}

bool WorkScript::ArrayType::equals(const Type * type) const
{
	if (!Type::equals(type))return false;
	const ArrayType *targetArray = (const ArrayType*)type;
	if (!this->targetType->equals(targetArray->targetType))return false;
	if (this->lengthOfEachDimension.size() != targetArray->lengthOfEachDimension.size())return false;
	return true;
}

ArrayType * WorkScript::ArrayType::get(Type * targetType, const std::vector<size_t>& lenOfEachDimension)
{
	wstring idStr = ArrayType::getIdentifierString(targetType, lengthOfEachDimension);
	auto it = types.find(idStr);
	if (it != types.end())return it->second;
	return (types[idStr] = new ArrayType(targetType, lengthOfEachDimension));
}

void WorkScript::ArrayType::releaseTypes()
{
	for (auto it : types) {
		delete it.second;
	}
}
