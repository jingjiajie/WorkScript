#include "stdafx.h"
#include "PointerType.h"
#include "WorkScriptException.h"
#include "Location.h"

using namespace WorkScript;
using namespace std;

PointerType::PointerType(Program * program, const std::wstring & name, Type *targetType, unsigned int level)
	:Type(program, name), targetType(targetType) ,level(level){}

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
	PointerType *target = (PointerType*)type;
	return this->level == target->level && this->targetType->equals(target->targetType);
}
