#include "PointerType.h"
#include "Report.h"
#include "DebugInfo.h"
#include <sstream>

using namespace WorkScript;
using namespace std;

std::unordered_map<std::wstring, PointerType*> PointerType::types;
Finalizer PointerType::staticFinalizer(&PointerType::releaseTypes);

PointerType::PointerType(Type *targetType, size_t level, bool isConst, bool isVolatile) noexcept
	:targetType(targetType), level(level), _const(isConst),_volatile(isVolatile) {}

std::wstring WorkScript::PointerType::getName() const noexcept
{
	wstring name = this->targetType->getName();
	for (size_t j = 0; j < this->level; ++j) {
		name += L"*";
	}
	if (this->_const) { name += L" const"; }
	if (this->_volatile) { name += L" volatile"; }
	return name;
}

std::wstring WorkScript::PointerType::getMangledName() const noexcept
{
	return PointerType::getMangledName(this->targetType, this->level, this->_const, this->_volatile);
}

TypeClassification PointerType::getClassification() const noexcept
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

bool PointerType::equals(const Type * type) const noexcept
{
	if (type->getClassification() != TypeClassification::POINTER)return false;
	const PointerType *target = (const PointerType*)type;
	return this->level == target->level && this->targetType->equals(target->targetType);
}

std::wstring WorkScript::PointerType::getMangledName(Type * targetType, size_t level, bool isConst, bool isVolatile) noexcept
{
	wstringstream name;
	//TODO 各层指针都可以const
	if(isConst) name << L"K";
	for(size_t i=0; i< level; ++i) {
		name << L"P";
	}
	name << targetType->getMangledName();
	return name.str();
}

PointerType * WorkScript::PointerType::get(Type * targetType, size_t pointerLevel, bool isConst, bool isVolatile) noexcept
{
	wstring idStr = PointerType::getMangledName(targetType, pointerLevel, isConst, isVolatile);
	auto it = types.find(idStr);
	if (it != types.end()) return it->second;
	else return (types[idStr] = new PointerType(targetType, pointerLevel, isConst, isVolatile));
}

void WorkScript::PointerType::releaseTypes() noexcept
{
	for (auto it : types) {
		delete it.second;
	}
}
