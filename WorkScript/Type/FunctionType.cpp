#include <sstream>
#include "FunctionType.h"
#include "VoidType.h"
#include "ValueDescriptor.h"

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

std::wstring WorkScript::FunctionType::getMangledName() const noexcept
{
	return FunctionType::getMangledName(this->paramTypes, this->returnType, this->rumtimeVarargs, this->_const);
}

std::wstring WorkScript::FunctionType::getMangledName(const std::vector<Type*>& paramTypes, Type * returnType, bool isRuntimeVarargs, bool isConst) noexcept
{
	wstringstream ss;
	//TODO 未测试，只有参数为函数指针类型才会调用这个getMangledName，否则应该调用Function::getMangledName()
	ss << L"F";
	if (returnType)
	{
		ss <<returnType->getMangledName();
	}
	if(paramTypes.empty()){
		ss << VoidType::get()->getMangledName();
	}else
	{
		for (size_t i = 0; i < paramTypes.size(); ++i)
		{
			ss << paramTypes[i] ? L"?" : paramTypes[i]->getMangledName();
		}
	}
    if(isRuntimeVarargs){
        ss << L"z";
    }
	ss << L"E";
	return ss.str();
}

FunctionType * FunctionType::get(const std::vector<Type*> &paramTypes, Type * returnType, bool isRuntimeVarargs, bool isConst) noexcept
{
	wstring idStr = FunctionType::getMangledName(paramTypes, returnType, isRuntimeVarargs, isConst);
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

bool FunctionType::matchExact(const DebugInfo &d,const FunctionType *declType, const FunctionTypeQuery &query) noexcept
{
	const vector<Type *> &realParamTypes = query.getParameterTypes();
	size_t declParamCount = declType->paramTypes.size();
	if (declType->isConst() != query.isConst()) return false;
	if (realParamTypes.size() != declParamCount)return false;
	if (query.isRuntimeVarargs() != declType->isRumtimeVarargs()) return false;
	for (size_t i = 0; i < declParamCount; ++i)
	{
		Type *formalParamType = declType->paramTypes[i];
		if (!realParamTypes[i] && !formalParamType) continue;
		if (!realParamTypes[i] || !formalParamType) return false;
		if (!formalParamType->equals(realParamTypes[i])) return false;
	}
	return true;
}

bool FunctionType::matchCall(const DebugInfo &d,const FunctionType *declType, const FunctionTypeQuery &query) noexcept
{
    const vector<Type *> &realParamTypes = query.getParameterTypes();
    size_t declParamCount = declType->paramTypes.size();
    if (!declType->isConst() && query.isConst()) return false;
    if (realParamTypes.size() < declParamCount)return false;
    if (realParamTypes.size() > declParamCount && !declType->isRumtimeVarargs()) return false;
    for (size_t i = 0; i < declParamCount; ++i) {
        Type *formalParamType = declType->paramTypes[i];
        if (!realParamTypes[i])continue;
        if (formalParamType &&
            !ValueDescriptor::convertableTo(d, ValueDescriptor(realParamTypes[i], ValueKind::VARIABLE),
                                            ValueDescriptor(formalParamType, ValueKind::VARIABLE)))
            return false;
    }
    return true;
}

bool FunctionType::matchCall(const DebugInfo &d, const FunctionTypeQuery &query)const noexcept
{
	return FunctionType::matchCall(d, this, query);
}

bool FunctionType::matchExact(const DebugInfo &d, const FunctionTypeQuery &query)const noexcept
{
	return FunctionType::matchExact(d, this, query);
}
