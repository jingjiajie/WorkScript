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

FloatType::FloatType(unsigned char length, bool isConst, bool isVolatile) noexcept
	:length(length), _const(isConst),_volatile(isVolatile)
{
}

std::wstring WorkScript::FloatType::getName() const noexcept
{
	wstring str;
	if(this->_const) str += L"const ";
	if(this->_volatile) str += L"volatile ";
	str += L"float" + to_wstring(this->length);
	return str;
}

std::wstring WorkScript::FloatType::getIdentifierString() const noexcept
{
	return FloatType::getIdentifierString(this->length, this->_const, this->_volatile);
}

std::wstring FloatType::getIdentifierString(unsigned char length, bool isConst, bool isVolatile) noexcept
{
	wstring str = L"f" + to_wstring(length);
	if (isConst)str += L".c";
	if (isVolatile) str += L".v";
	return str;
}

TypeClassification WorkScript::FloatType::getClassification() const noexcept
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
		throw InternalException(L"不支持的浮点类型长度：" + to_wstring(this->length));
	}
}

bool WorkScript::FloatType::equals(const Type * type) const noexcept
{
	if (type->getClassification() != TypeClassification::FLOAT)return false;
	const FloatType *target = (const FloatType*)type;
	if (this->length != target->length)return false;
	return true;
}

void WorkScript::FloatType::releaseTypes() noexcept
{
	for (auto it : types) {
		delete it.second;
	}
}

FloatType * WorkScript::FloatType::get(unsigned char length, bool isConst, bool isVolatile) noexcept
{
	wstring idStr = FloatType::getIdentifierString(length, isConst, isVolatile);
	auto it = types.find(idStr);
	if (it != types.end()) return it->second;
	else return (types[idStr] = new FloatType(length, isConst, isVolatile));
}