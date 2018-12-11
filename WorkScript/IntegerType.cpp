#include "stdafx.h"
#include "IntegerType.h"
#include "Function.h"
#include "NativeOverload.h"
#include "Program.h"

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
		return llvm::IntegerType::getInt8Ty(*ctx->getLLVMContext());
	case 2:
		return llvm::IntegerType::getInt16Ty(*ctx->getLLVMContext());
	case 4:
		return llvm::IntegerType::getInt32Ty(*ctx->getLLVMContext());
	case 8:
		return llvm::IntegerType::getInt64Ty(*ctx->getLLVMContext());
	default:
		throw WorkScriptException(L"不支持的整数长度："+this->length);
	}
}
