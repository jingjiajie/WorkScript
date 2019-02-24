#include "Type.h"
#include "Function.h"
#include "Program.h"
#include "Utils.h"
#include "FloatType.h"
#include "Exception.h"

using namespace std;
using namespace WorkScript;

std::unordered_map<std::wstring, FloatType*> FloatType::types;
Finalizer FloatType::staticFinalizer(&FloatType::releaseTypes);

FloatType::FloatType(FloatTypeClassification cls, bool isConst, bool isVolatile) noexcept
	:classification(cls), _const(isConst),_volatile(isVolatile)
{
}

std::wstring WorkScript::FloatType::getName() const noexcept
{
	wstring str;
	if(this->_const) str += L"const ";
	if(this->_volatile) str += L"volatile ";
	switch(this->classification){
		case FloatTypeClassification::FLOAT:
			str += L"float";
			break;
		case FloatTypeClassification::DOUBLE:
			str += L"double";
			break;
//		case FloatTypeClassification::LONG_DOUBLE:
//			str += L"long double";
//			break;
	}
	return str;
}

std::wstring WorkScript::FloatType::getMangledName() const noexcept
{
	return FloatType::getMangledName(this->classification, this->_const, this->_volatile);
}

std::wstring FloatType::getMangledName(FloatTypeClassification cls, bool isConst, bool isVolatile) noexcept{
	wstring name;
	if(isConst) name += L"K";
	switch(cls){
		case FloatTypeClassification::FLOAT:
			name += L"f";
			break;
		case FloatTypeClassification::DOUBLE:
			name += L"d";
			break;
//		case FloatTypeClassification::LONG_DOUBLE:
//			name += L"e";
//			break;
	}
	return name;
}

TypeClassification WorkScript::FloatType::getClassification() const noexcept
{
	return TypeClassification::FLOAT;
}

llvm::Type * WorkScript::FloatType::getLLVMType(GenerateContext *context) const
{
	llvm::LLVMContext &ctx = *context->getLLVMContext();
	auto len = this->getLength();
	switch (len)
	{
	case 32:
		return llvm::Type::getFloatTy(ctx);
	case 64:
		return llvm::Type::getDoubleTy(ctx);
	default:
		throw InternalException(L"不支持的浮点类型长度：" + to_wstring(len));
	}
}

bool WorkScript::FloatType::equals(const Type * type) const noexcept
{
	if (type->getClassification() != TypeClassification::FLOAT)return false;
	auto *target = (const FloatType*)type;
	if (this->classification != target->classification)return false;
	return true;
}

void WorkScript::FloatType::releaseTypes() noexcept
{
	for (auto it : types) {
		delete it.second;
	}
}

FloatType * WorkScript::FloatType::get(FloatTypeClassification cls, bool isConst, bool isVolatile) noexcept
{
	wstring idStr = FloatType::getMangledName(cls, isConst, isVolatile);
	auto it = types.find(idStr);
	if (it != types.end()) return it->second;
	else return (types[idStr] = new FloatType(cls, isConst, isVolatile));
}

unsigned FloatType::getLength() const noexcept
{
	switch(this->classification) {
		case FloatTypeClassification::FLOAT:
			return 32;
		case FloatTypeClassification::DOUBLE:
			return 64;
//		case FloatTypeClassification::LONG_DOUBLE:
//			return 80;
	}
}