#include "stdafx.h"
#include "FloatPointerType.h"

using namespace std;
using namespace WorkScript;

WorkScript::FloatPointerType::FloatPointerType(Program * program, const std::wstring & name, unsigned char length)
	:Type(program,name)
{
	this->length = length;
}

TypeClassification WorkScript::FloatPointerType::getClassification() const
{
	return TypeClassification::FLOAT_POINTER;
}

llvm::Type * WorkScript::FloatPointerType::getLLVMType(GenerateContext * context) const
{
	llvm::LLVMContext &ctx = *context->getLLVMContext();
	switch (this->length)
	{
	case 32:
		return llvm::Type::getFloatPtrTy(ctx);
	case 64:
		return llvm::Type::getDoublePtrTy(ctx);
	default:
		throw WorkScriptException(L"不支持的浮点类型长度：" + this->length);
	}
}

bool WorkScript::FloatPointerType::equals(const Type * type) const
{
	if (!Type::equals(type))return false;
	FloatPointerType *target = (FloatPointerType*)type;
	if (this->length != target->length)return false;
	return true;
}
