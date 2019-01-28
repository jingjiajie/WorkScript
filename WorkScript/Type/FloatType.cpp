#include "Type.h"
#include "Function.h"
#include "Program.h"
#include "Utils.h"
#include "FloatType.h"

using namespace std;
using namespace WorkScript;

std::unordered_map<std::wstring, FloatType*> FloatType::types;
Finalizer FloatType::staticFinalizer(&FloatType::releaseTypes);

FloatType::FloatType(unsigned char length, bool isConst, bool isVolatile)
	:Type(isConst,isVolatile)
{
	this->length = length;
}

std::wstring WorkScript::FloatType::getName() const
{
	wstring str;
	if(this->_const) str += L"const ";
	if(this->_volatile) str += L"volatile ";
	str += L"float" + to_wstring(this->length);
	return str;
}

std::wstring WorkScript::FloatType::getIdentifierString() const
{
	return FloatType::getIdentifierString(this->length, this->_const, this->_volatile);
}

std::wstring FloatType::getIdentifierString(unsigned char length, bool isConst, bool isVolatile)
{
	wstring str = L"f" + to_wstring(length);
	if (isConst)str += L".c";
	if (isVolatile) str += L".v";
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
		throw WorkScriptException(DebugInfo() , L"不支持的浮点类型长度：" + to_wstring(this->length));
	}
}

bool WorkScript::FloatType::equals(const Type * type) const
{
	if (!Type::equals(type))return false;
	const FloatType *target = (const FloatType*)type;
	if (this->length != target->length)return false;
	return true;
}

void WorkScript::FloatType::releaseTypes()
{
	for (auto it : types) {
		delete it.second;
	}
}

FloatType * WorkScript::FloatType::get(unsigned char length, bool isConst, bool isVolatile)
{
	wstring idStr = FloatType::getIdentifierString(length, isConst, isVolatile);
	auto it = types.find(idStr);
	if (it != types.end()) return it->second;
	else return (types[idStr] = new FloatType(length, isConst, isVolatile));
}