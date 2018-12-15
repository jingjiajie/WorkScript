#include "stdafx.h"
#include "IntegerPointerType.h"

using namespace WorkScript;
using namespace std;

WorkScript::IntegerPointerType::IntegerPointerType(Program * program, const std::wstring & name, unsigned char length, bool isSigned)
	:Type(program,name)
{
	this->length = length;
	this->_signed = isSigned;
}

TypeClassification WorkScript::IntegerPointerType::getClassification() const
{
	return TypeClassification::INTEGER_POINTER;
}

llvm::Type * WorkScript::IntegerPointerType::getLLVMType(GenerateContext * ctx) const
{

	switch (this->length)
	{
	case 1:
		return llvm::IntegerType::getInt1PtrTy(*ctx->getLLVMContext());
	case 8:
		return llvm::IntegerType::getInt8PtrTy(*ctx->getLLVMContext());
	case 16:
		return llvm::IntegerType::getInt16PtrTy(*ctx->getLLVMContext());
	case 32:
		return llvm::IntegerType::getInt32PtrTy(*ctx->getLLVMContext());
	case 64:
		return llvm::IntegerType::getInt64PtrTy(*ctx->getLLVMContext());
	default:
		throw WorkScriptException(L"不支持的整数长度：" + this->length);
	}
}

bool WorkScript::IntegerPointerType::equals(const Type * type) const
{
	if (!Type::equals(type))return false;
	IntegerPointerType *target = (IntegerPointerType*)type;
	if (target->getLength() != this->getLength())return false;
	if (target->isSigned() != this->isSigned())return false;
	return true;
}
