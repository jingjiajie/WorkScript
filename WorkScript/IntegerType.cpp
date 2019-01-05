#include "stdafx.h"
#include "IntegerType.h"
#include "Program.h"
#include "WorkScriptException.h"
#include "Location.h"

using namespace std;
using namespace WorkScript;


WorkScript::IntegerType::IntegerType(Program * program, const std::wstring & name, unsigned char length, bool isSigned)
	:Type(program,name)
{
	this->length = length;
	this->_signed = isSigned;
}

TypeClassification WorkScript::IntegerType::getClassification() const
{
	return TypeClassification::INTEGER;
}

llvm::Type * WorkScript::IntegerType::getLLVMType(GenerateContext *ctx) const
{
	switch (this->length)
	{
	case 1:
		return llvm::IntegerType::getInt1Ty(*ctx->getLLVMContext());
	case 8:
		return llvm::IntegerType::getInt8Ty(*ctx->getLLVMContext());
	case 16:
		return llvm::IntegerType::getInt16Ty(*ctx->getLLVMContext());
	case 32:
		return llvm::IntegerType::getInt32Ty(*ctx->getLLVMContext());
	case 64:
		return llvm::IntegerType::getInt64Ty(*ctx->getLLVMContext());
	default:
		//TODO Location信息
		throw WorkScriptException(Location(), L"不支持的整数长度："+this->length);
	}
}

bool WorkScript::IntegerType::equals(const Type * type) const
{
	if (!Type::equals(type))return false;
	IntegerType *target = (IntegerType*)type;
	if (target->getLength() != this->getLength())return false;
	if (target->isSigned() != this->isSigned())return false;
	return true;
}
