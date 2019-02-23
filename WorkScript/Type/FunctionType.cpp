#include <sstream>
#include "FunctionType.h"

using namespace WorkScript;
using namespace std;

std::unordered_map<std::wstring, FunctionType*> FunctionType::types;
Finalizer FunctionType::staticFinalizer(&FunctionType::releaseTypes);

TypeClassification FunctionType::getClassification() const noexcept
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

bool WorkScript::FunctionType::equals(const Type * type) const noexcept
{
	if (type->getClassification() != TypeClassification::FUNCTION) return false;
	const FunctionType *targetFuncType = (const FunctionType*)type;
	if (!targetFuncType->returnType->equals(this->returnType))return false;
	if (targetFuncType->paramTypes.size() != this->paramTypes.size())return false;
	for (size_t i = 0; i < this->paramTypes.size(); ++i) {
		if (!targetFuncType->paramTypes[i]->equals(this->paramTypes[i])) {
			return false;
		}
	}
	if(targetFuncType->isRumtimeVarargs() != this->isRumtimeVarargs()) return false;
	if(targetFuncType->isConst() != this->isConst()) return false;
	return true;
}

std::wstring WorkScript::FunctionType::getName() const noexcept
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
	return ss.str();
}

std::wstring WorkScript::FunctionType::getIdentifierString() const noexcept
{
	return FunctionType::getIdentifierString(this->paramTypes, this->returnType, this->rumtimeVarargs, this->_const);
}

std::wstring WorkScript::FunctionType::getIdentifierString(const std::vector<Type*>& paramTypes, Type * returnType, bool isRuntimeVarargs, bool isConst) noexcept
{
	wstringstream ss;
	ss << L"f";
	if (returnType)
	{
		ss << L".r@" << returnType->getName();
	}
	ss << L".p";
	for (size_t i = 0; i < paramTypes.size(); ++i)
	{
		ss << L"@" << (paramTypes[i] ? paramTypes[i]->getName() : L"?");
	}
	if (isRuntimeVarargs)
	{
		ss << L"@...";
	}
	if (isConst)
	{
		ss << L"@.c";
	}
	return ss.str();
}

FunctionType * FunctionType::get(const std::vector<Type*> &paramTypes, Type * returnType, bool isRuntimeVarargs, bool isConst) noexcept
{
	wstring idStr = FunctionType::getIdentifierString(paramTypes, returnType, isRuntimeVarargs, isConst);
	auto it = types.find(idStr);
	if (it != types.end()) return it->second;
	else return (types[idStr] = new FunctionType(paramTypes, returnType, isRuntimeVarargs, isConst));
}

void WorkScript::FunctionType::releaseTypes() noexcept
{
	for (auto it : types) {
		delete it.second;
	}
}

bool FunctionType::match(const DebugInfo &d,const FunctionType *declType, const FunctionTypeQuery &query) noexcept
{
	const vector<Type*> &realParamTypes = query.getParameterTypes();
	size_t declParamCount = declType->paramTypes.size();
	bool isStrict = query.isStrict();
	if(isStrict){
		if(declType->isConst() != query.isConst()) return false;
		//TODO 需要考虑参数默认值
		if (realParamTypes.size() != declParamCount)return false;
		if(query.isRuntimeVarargs() != declType->isRumtimeVarargs()) return false;
		for (size_t i = 0; i < declParamCount; ++i)
		{
			Type *formalParamType = declType->paramTypes[i];
			if (!realParamTypes[i] && !formalParamType) continue;
			if (!realParamTypes[i] || !formalParamType) return false;
			if (!formalParamType->equals(realParamTypes[i])) return false;
		}
		return true;
	}else{
		if(!declType->isConst() && query.isConst()) return false;
		//TODO 需要考虑参数默认值
		if (realParamTypes.size() < declParamCount)return false;
		if (realParamTypes.size() > declParamCount && !declType->isRumtimeVarargs()) return false;
		for (size_t i = 0; i < declParamCount; ++i)
		{
			Type *formalParamType = declType->paramTypes[i];
			if (!realParamTypes[i])continue;
			if (formalParamType && !Type::convertableTo(d, realParamTypes[i], formalParamType)) return false;
		}
		return true;
	}
}

bool FunctionType::match(const DebugInfo &d, const FunctionTypeQuery &query)const noexcept
{
	return FunctionType::match(d, this, query);
}
