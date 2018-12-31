#include "stdafx.h"
#include "PointerType.h"
#include "WorkScriptException.h"

using namespace WorkScript;
using namespace std;

PointerType::PointerType(Program * program, const std::wstring & name, Type *targetType)
	:Type(program, name), targetType(targetType) {}

TypeClassification PointerType::getClassification() const
{
	return TypeClassification::POINTER;
}

llvm::Type * PointerType::getLLVMType(GenerateContext * ctx) const
{
	//switch (this->length)
	//{
	//case 1:
	//	return llvm::IntegerType::getInt1PtrTy(*ctx->getLLVMContext());
	//case 8:
	//	return llvm::IntegerType::getInt8PtrTy(*ctx->getLLVMContext());
	//case 16:
	//	return llvm::IntegerType::getInt16PtrTy(*ctx->getLLVMContext());
	//case 32:
	//	return llvm::IntegerType::getInt32PtrTy(*ctx->getLLVMContext());
	//case 64:
	//	return llvm::IntegerType::getInt64PtrTy(*ctx->getLLVMContext());
	//default:
	//	throw WorkScriptException(L"不支持的整数长度：" + this->length);
	//}
	throw UnimplementedException(L"未实现");
}

bool PointerType::equals(const Type * type) const
{
	if (!Type::equals(type))return false;
	PointerType *target = (PointerType*)type;
	return this->targetType->equals(target->targetType);
}
