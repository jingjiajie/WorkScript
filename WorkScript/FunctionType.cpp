#include "stdafx.h"
#include "FunctionType.h"

using namespace WorkScript;
using namespace std;

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

std::wstring WorkScript::FunctionType::getName(const std::vector<Type*>& paramTypes, Type * returnType)
{
	wstringstream ss;
	ss << L"f";
	if (returnType) {
		ss << L"@" << returnType->getName();
	}
	for (size_t i = 0; i < paramTypes.size(); ++i) {
		ss << L"@" << (paramTypes[i] ? paramTypes[i]->getName() : L"?");
	}
	return ss.str();
}
