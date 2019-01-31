#include "IntegerType.h"
#include "Program.h"
#include "Report.h"
#include "Exception.h"
#include "DebugInfo.h"

using namespace std;
using namespace WorkScript;

std::unordered_map<std::wstring, IntegerType*> IntegerType::types;
Finalizer IntegerType::staticFinalizer(&IntegerType::releaseTypes);

WorkScript::IntegerType::IntegerType(unsigned char length, bool isSigned, bool isConst, bool isVolatile)
	:Type(isConst, isVolatile)
{
	this->length = length;
	this->_signed = isSigned;
}

std::wstring WorkScript::IntegerType::getName() const
{
	wstring str;
	if(this->_const) str += L"const ";
	if(this->_volatile) str += L"volatile ";
	if(!this->_signed) str += L"unsigned ";
	str += L"int" + to_wstring(this->length);
	return str;
}


std::wstring WorkScript::IntegerType::getIdentifierString() const
{
	return IntegerType::getIdentifierString(this->length, this->_signed, this->_const, this->_volatile);
}

std::wstring IntegerType::getIdentifierString(unsigned char length, bool isSigned, bool isConst, bool isVolatile)
{
	wstring str = (isSigned ? L"si" : L"ui") + to_wstring(length);
	if (isConst)str += L".c";
	if (isVolatile) str += L".v";
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
		throw InternalException(L"不支持的整数长度：" + to_wstring(this->length));
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

void WorkScript::IntegerType::releaseTypes()
{
	for (auto it : types) {
		delete it.second;
	}
}

IntegerType* IntegerType::get(unsigned char length, bool isSigned, bool isConst, bool isVolatile)
{
	wstring idStr = IntegerType::getIdentifierString(length, isSigned, isConst, isVolatile);
	auto it = types.find(idStr);
	if (it != IntegerType::types.end()) return it->second;
	else return (types[idStr] = new IntegerType(length, isSigned, isConst, isVolatile));
}