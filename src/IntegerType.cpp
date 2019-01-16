#include "IntegerType.h"
#include "Program.h"
#include "WorkScriptException.h"
#include "Location.h"

using namespace std;
using namespace WorkScript;

IntegerType IntegerType::sint8(L"sint8", 8, true);
IntegerType IntegerType::sint16(L"sint16", 16, true);
IntegerType IntegerType::sint32(L"sint32", 32, true);
IntegerType IntegerType::sint64(L"sint64", 64, true);
IntegerType IntegerType::uint1(L"uint1", 1, false);
IntegerType IntegerType::uint8(L"uint8", 8, false);
IntegerType IntegerType::uint16(L"uint16", 16, false);
IntegerType IntegerType::uint32(L"uint32", 32, false);
IntegerType IntegerType::uint64(L"uint64", 64, false);

WorkScript::IntegerType::IntegerType(const std::wstring & name, unsigned char length, bool isSigned, bool isConst, bool isVolatile)
	:Type(isConst, isVolatile), name(name)
{
	this->length = length;
	this->_signed = isSigned;
}

std::wstring WorkScript::IntegerType::getName() const
{
	return this->name;
}

std::wstring WorkScript::IntegerType::getIdentifierString() const
{
	wstring str = (this->_signed ? L"si" : L"ui") + to_wstring(this->length);
	if (this->isConst())str += L".c";
	if (this->isVolatile()) str += L".v";
	return str;
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
	const IntegerType *target = (const IntegerType*)type;
	if (target->getLength() != this->getLength())return false;
	if (target->isSigned() != this->isSigned())return false;
	return true;
}
