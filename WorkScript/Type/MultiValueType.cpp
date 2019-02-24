#include "MultiValueType.h"
#include "Exception.h"
#include <sstream>

using namespace std;
using namespace WorkScript;

unordered_map<std::wstring, MultiValueType*> MultiValueType::types;
Finalizer MultiValueType::staticFinalizer(&MultiValueType::releaseTypes);

void MultiValueType::releaseTypes() noexcept
{
    for(const auto &it : MultiValueType::types){
        delete it.second;
    }
}

TypeClassification MultiValueType::getClassification() const noexcept
{
    return TypeClassification::MULTI_VALUE;
}

llvm::Type *MultiValueType::getLLVMType(GenerateContext *context) const
{
    throw InternalException(L"MultiValueType无法生成LLVM Type");
}

std::wstring MultiValueType::getName() const noexcept
{
    wstringstream ss;
    for(size_t i=0; i<this->itemTypes.size(); ++i){
        if(i != 0) ss << L", ";
        ss << this->itemTypes[i]->getName();
    }
    return ss.str();
}

MultiValueType::MultiValueType(const std::vector<Type *> &itemTypes) noexcept
{
    vector<Type*> flatedItemTypes;
    flatedItemTypes.reserve(itemTypes.size());
    for(Type *type : itemTypes)
    {
        if(type->getClassification() == TypeClassification::MULTI_VALUE)
        {
            auto multiValueType = static_cast<MultiValueType*>(type);
            flatedItemTypes.insert(flatedItemTypes.end(), multiValueType->itemTypes.begin(), multiValueType->itemTypes.end());
        }else{
            flatedItemTypes.push_back(type);
        }
    }
    this->itemTypes = flatedItemTypes;
}

bool MultiValueType::equals(const Type *type) const noexcept
{
    if(type->getClassification() != TypeClassification::MULTI_VALUE) return false;
    auto multiValueType = (MultiValueType*)type;
    if(multiValueType->itemTypes.size() != this->itemTypes.size()) return false;
    for(size_t i=0;i<this->itemTypes.size(); ++i){
        if(!this->itemTypes[i]->equals(multiValueType->itemTypes[i])) return false;
    }
    return true;
}

std::wstring
MultiValueType::getMangledName(const std::vector<Type *> &itemTypes) noexcept
{
    wstringstream ss;
    for(size_t i=0; i<itemTypes.size(); ++i){
        ss << itemTypes[i]->getMangledName();
    }
    return ss.str();
}

std::wstring MultiValueType::getMangledName() const noexcept
{
    return MultiValueType::getMangledName(this->itemTypes);
}

MultiValueType *MultiValueType::get(const std::vector<Type *> &itemTypes) noexcept
{
    wstring idStr = MultiValueType::getMangledName(itemTypes);
    auto it = types.find(idStr);
    if (it != types.end()) return it->second;
    else return (types[idStr] = new MultiValueType(itemTypes));
}
