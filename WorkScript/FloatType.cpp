#include "stdafx.h"
#include "Type.h"
#include "Function.h"
#include "Program.h"
#include "Utils.h"
#include "FloatType.h"

using namespace std;
using namespace WorkScript;

FloatType::FloatType(Program * program, const std::wstring & name, unsigned char length)
	:Type(program,name)
{
	this->length = length;
}

TypeClassification WorkScript::FloatType::getClassification() const
{
	return TypeClassification::FLOAT;
}

llvm::Type * WorkScript::FloatType::getLLVMType(GenerateContext *context) const
{
	llvm::LLVMContext &ctx = *context->getLLVMContext();
	switch (this->length)
	{
	case 32:
		return llvm::Type::getFloatTy(ctx);
	case 64:
		return llvm::Type::getDoubleTy(ctx);
	default:
		throw WorkScriptException(Location() , L"不支持的浮点类型长度：" + this->length);
	}
}

bool WorkScript::FloatType::equals(const Type * type) const
{
	if (!Type::equals(type))return false;
	FloatType *target = (FloatType*)type;
	if (this->length != target->length)return false;
	return true;
}
