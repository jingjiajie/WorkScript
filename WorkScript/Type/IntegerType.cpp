#include "IntegerType.h"
#include "Program.h"
#include "Report.h"
#include "Exception.h"
#include "DebugInfo.h"
#include "GenerateContext.h"

using namespace std;
using namespace WorkScript;

std::unordered_map<std::wstring, IntegerType*> IntegerType::types;
Finalizer IntegerType::staticFinalizer(&IntegerType::releaseTypes);

WorkScript::IntegerType::IntegerType(IntegerTypeClassification cls, bool isSigned, bool isConst, bool isVolatile) noexcept
	:classification(cls), _signed(isSigned), _const(isConst),_volatile(isVolatile)
{
}

std::wstring WorkScript::IntegerType::getName() const noexcept
{
	wstring str;
	if(this->_const) str += L"const ";
	if(this->_volatile) str += L"volatile ";
	if(!this->_signed) str += L"unsigned ";
	switch(this->classification)
	{
		case IntegerTypeClassification::BOOL:
			str += L"bool";
			break;
		case IntegerTypeClassification::CHAR:
			str += L"char";
			break;
		case IntegerTypeClassification::SHORT:
			str += L"short";
			break;
		case IntegerTypeClassification::INT :
			str += L"int";
			break;
		case IntegerTypeClassification::LONG:
			str += L"long";
			break;
		case IntegerTypeClassification::LONG_LONG:
			str += L"long long";
			break;
	}
	return str;
}


TypeClassification WorkScript::IntegerType::getClassification() const noexcept
{
	return TypeClassification::INTEGER;
}

unsigned IntegerType::getLength() const noexcept
{
	switch(this->classification)
	{
		case IntegerTypeClassification::BOOL:
			return 1;
		case IntegerTypeClassification::CHAR:
			return 8;
		case IntegerTypeClassification::SHORT:
			return 16;
		case IntegerTypeClassification::INT:
			return 32;
		case IntegerTypeClassification::LONG:
			return 64;
		case IntegerTypeClassification::LONG_LONG:
			return 64;
	}
}

llvm::Type * WorkScript::IntegerType::getLLVMType(GenerateContext *ctx) const
{
	auto len = this->getLength();
	switch (len)
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
			throw InternalException(L"不支持的整数长度");
	}
}

bool WorkScript::IntegerType::equals(const Type * type) const noexcept
{
	if (type->getClassification() != TypeClassification::INTEGER)return false;
	auto *target = (const IntegerType*)type;
	if (target->getLength() != this->getLength())return false;
	if (target->isSigned() != this->isSigned())return false;
	return true;
}

void WorkScript::IntegerType::releaseTypes() noexcept
{
	for (const auto &it : types) {
		delete it.second;
	}
}

IntegerType* IntegerType::get(IntegerTypeClassification cls, bool isSigned, bool isConst, bool isVolatile) noexcept
{
	wstring idStr = IntegerType::getMangledName(cls, isSigned, isConst, isVolatile);
	auto it = types.find(idStr);
	if (it != IntegerType::types.end()) return it->second;
	else return (types[idStr] = new IntegerType(cls, isSigned, isConst, isVolatile));
}

std::wstring IntegerType::getMangledName() const noexcept
{
    return IntegerType::getMangledName(this->classification, this->_signed, this->_const, this->_volatile);
}

std::wstring IntegerType::getMangledName(IntegerTypeClassification cls, bool isSigned, bool isConst, bool isVolatile) noexcept
{
	std::wstring name;
	if(isConst) name += L"K";
    switch(cls) {
		case IntegerTypeClassification::BOOL : {
			name += L"b";
			break;
		}
		case IntegerTypeClassification::CHAR: {
			name += isSigned ? L"c" : L"h";
			break;
		}
		case IntegerTypeClassification::SHORT: {
			name += isSigned ? L"s" : L"t";
			break;
		}
		case IntegerTypeClassification::INT: {
			name += isSigned ? L"i" : L"j";
			break;
		}
		case IntegerTypeClassification::LONG: {
			name += isSigned ? L"l" : L"m";
			break;
		}
		case IntegerTypeClassification::LONG_LONG: {
			name += isSigned ? L"x" : L"y";
			break;
		}
	}
	return name;
}