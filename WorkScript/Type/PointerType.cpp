#include "PointerType.h"
#include "WorkScriptException.h"
#include "DebugInfo.h"

using namespace WorkScript;
using namespace std;

std::unordered_map<std::wstring, PointerType*> PointerType::types;
Finalizer PointerType::staticFinalizer(&PointerType::releaseTypes);

PointerType::PointerType(Type *targetType, size_t level, bool isConst, bool isVolatile)
	:Type(isConst, isVolatile), targetType(targetType), level(level) {}

std::wstring WorkScript::PointerType::getName() const
{
	wstring name = this->targetType->getName();
	for (size_t j = 0; j < this->level; ++j) {
		name += L"*";
	}
	if (this->_const) { name += L" const"; }
	if (this->_volatile) { name += L" volatile"; }
	return name;
}

std::wstring WorkScript::PointerType::getIdentifierString() const
{
	wstring name = this->targetType->getIdentifierString();
	for (size_t j = 0; j < this->level; ++j) {
		name += L"*";
	}
	if (this->_const) { name += L"@.c"; }
	if (this->_volatile) { name += L" @.v"; }
	return name;
}

TypeClassification PointerType::getClassification() const
{
	return TypeClassification::POINTER;
}

llvm::Type * PointerType::getLLVMType(GenerateContext * ctx) const
{
	llvm::Type *llvmType = this->targetType->getLLVMType(ctx);
	for (unsigned i = 0; i < this->level; ++i) {
		llvmType = llvm::PointerType::get(llvmType, 0U);
	}
	return llvmType;
}

bool PointerType::equals(const Type * type) const
{
	if (!Type::equals(type))return false;
	const PointerType *target = (const PointerType*)type;
	return this->level == target->level && this->targetType->equals(target->targetType);
}

std::wstring WorkScript::PointerType::getIdentifierString(Type * targetType, size_t level, bool isConst, bool isVolatile)
{
	wstring name = targetType->getName();
	name += L"*" + to_wstring(level);
	if (isConst) {
		name += L"@.c";
	}
	if (isVolatile) {
		name += L"@.v";
	}
	return name;
}

PointerType * WorkScript::PointerType::get(Type * targetType, size_t pointerLevel, bool isConst, bool isVolatile)
{
	wstring idStr = PointerType::getIdentifierString(targetType, pointerLevel, isConst, isVolatile);
	auto it = types.find(idStr);
	if (it != types.end()) return it->second;
	else return (types[idStr] = new PointerType(targetType, pointerLevel, isConst, isVolatile));
}

void WorkScript::PointerType::releaseTypes()
{
	for (auto it : types) {
		delete it.second;
	}
}
