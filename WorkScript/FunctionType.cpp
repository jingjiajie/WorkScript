#include "stdafx.h"
#include "FunctionType.h"

using namespace WorkScript;
using namespace std;

std::unordered_map<std::wstring, FunctionType*> FunctionType::types;
Finalizer FunctionType::staticFinalizer(&FunctionType::releaseTypes);

TypeClassification FunctionType::getClassification() const
{
	return TypeClassification::FUNCTION;
}

llvm::Type * WorkScript::FunctionType::getLLVMType(GenerateContext * context) const
{
	size_t paramCount = this->paramTypes.size();
	vector<llvm::Type*> paramLLVMTypes;
	paramLLVMTypes.reserve(paramCount);
	for (size_t i = 0; i < paramCount; ++i) {
		paramLLVMTypes.push_back(this->paramTypes[i]->getLLVMType(context));
	}
	auto llvmType = llvm::FunctionType::get(this->returnType->getLLVMType(context), paramLLVMTypes, false);
	return llvmType;
}

bool WorkScript::FunctionType::equals(const Type * type) const
{
	if (!Type::equals(type))return false;
	FunctionType *targetFuncType = (FunctionType*)type;
	if (!targetFuncType->returnType->equals(this->returnType))return false;
	if (targetFuncType->paramTypes.size() != this->paramTypes.size())return false;
	for (size_t i = 0; i < this->paramTypes.size(); ++i) {
		if (!targetFuncType->paramTypes[i]->equals(this->paramTypes[i])) {
			return false;
		}
	}
	return true;
}

std::wstring WorkScript::FunctionType::getName() const
{
	wstringstream ss;
	if (this->returnType) {
		ss << this->returnType->getName();
	}
	ss << L"(";
	size_t paramCount = this->paramTypes.size();
	for (size_t i = 0; i < paramCount; ++i) {
		if (paramTypes[i]) {
			ss << paramTypes[i]->getName();
		}
		if (i != paramCount) { ss << L", "; }
	}
	ss << L")";
	if (this->_const) { ss << L" const"; }
	if (this->_volatile) { ss << L" volatile"; }
	return ss.str();
}

std::wstring WorkScript::FunctionType::getIdentifierString() const
{
	return FunctionType::getIdentifierString(this->paramTypes, this->returnType, this->rumtimeVarargs, this->staticVarargs, this->_const, this->_volatile);
}

std::wstring WorkScript::FunctionType::getIdentifierString(const std::vector<Type*>& paramTypes, Type * returnType, bool isRuntimeVarargs, bool isStaticVarargs, bool isConst, bool isVolatile)
{
	wstringstream ss;
	ss << L"f";
	if (returnType) {
		ss << L".r@" << returnType->getName();
	}
	ss << L".p";
	for (size_t i = 0; i < paramTypes.size(); ++i) {
		ss << L"@" << (paramTypes[i] ? paramTypes[i]->getName() : L"?");
	}
	if (isRuntimeVarargs) {
		ss << L"@...";
	}
	if (isStaticVarargs) {
		ss << L"@...s";
	}
	if (isConst) {
		ss << L"@.c";
	}
	if (isVolatile) {
		ss << L"@.v";
	}
	return ss.str();
}

FunctionType * WorkScript::FunctionType::get(std::vector<Type*> paramTypes, Type * returnType, bool isRuntimeVarargs, bool isStaticVarargs, bool isConst, bool isVolatile)
{
	wstring idStr = FunctionType::getIdentifierString(paramTypes, returnType, isRuntimeVarargs, isStaticVarargs);
	auto it = types.find(idStr);
	if (it != types.end()) return it->second;
	else return (types[idStr] = new FunctionType(paramTypes, returnType, isRuntimeVarargs, isStaticVarargs, isConst, isVolatile));
}

void WorkScript::FunctionType::releaseTypes()
{
	for (auto it : types) {
		delete it.second;
	}
}
