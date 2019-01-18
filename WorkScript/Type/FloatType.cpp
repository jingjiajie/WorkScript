#include "Type.h"
#include "Function.h"
#include "Program.h"
#include "Utils.h"
#include "FloatType.h"

using namespace std;
using namespace WorkScript;

FloatType FloatType::float32(L"float32", 32);
FloatType FloatType::float64(L"float64", 64);

FloatType::FloatType(const std::wstring & name, unsigned char length, bool isConst, bool isVolatile)
	:Type(isConst,isVolatile),name(name)
{
	this->length = length;
}

std::wstring WorkScript::FloatType::getIdentifierString() const
{
	wstring str = L"f" + to_wstring(this->length);
	if (this->isConst())str += L".c";
	if (this->isVolatile()) str += L".v";
	return str;
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
		throw WorkScriptException(Location() , L"不支持的浮点类型长度：" + to_wstring(this->length));
	}
}

bool WorkScript::FloatType::equals(const Type * type) const
{
	if (!Type::equals(type))return false;
	const FloatType *target = (const FloatType*)type;
	if (this->length != target->length)return false;
	return true;
}
