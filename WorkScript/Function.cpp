#include "stdafx.h"
#include "Function.h"
#include "Locale.h"
#include "InstantializeContext.h"
#include "FunctionType.h"

using namespace std;
using namespace WorkScript;

WorkScript::Function::Function(
	Program *program, 
	const std::wstring &name, 
	const std::vector<Type*>& paramTypes, 
	Type * returnType,
	bool declaredReturnType,
	bool isRuntimeVarargs,
	bool isStaticVarargs)
	:program(program),name(name), declaredReturnType(declaredReturnType),runtimeVarargs(isRuntimeVarargs),staticVarargs(isStaticVarargs)
{	
	FunctionType *funcType = program->getFunctionType(paramTypes, returnType);
	this->abstractType = funcType;
}

WorkScript::Function::~Function()
{

}

std::wstring WorkScript::Function::getStdParameterName(size_t paramIndex)
{
	return L"@" + to_wstring(paramIndex);
}

std::wstring WorkScript::Function::getMangledFunctionName(InstantializeContext *ctx) const
{
	wstringstream ss;
	ss << this->getName();
	for (auto paramType : this->getParameterTypes(ctx)) {
		ss << L"@" << paramType->getName();
	}
	return ss.str();
}

llvm::Function * WorkScript::Function::getLLVMFunction(GenerateContext * context, bool declareOnly)
{
	InstantializeContext *instCtx = context->getInstantializeContext();
	auto paramTypes = this->getParameterTypes(instCtx);
	llvm::Function *matchedFunc = nullptr;
	for (size_t i = 0; i < this->llvmFunctions.size(); ++i)
	{
		if (this->llvmFunctions[i].match(paramTypes)) matchedFunc = this->llvmFunctions[i].getLLVMFunction();
	}
	//如果没找到，则新生成一个LLVM Function
	if (!matchedFunc)
	{
		//生成函数类型
		vector<llvm::Type*> llvmParamTypes;
		llvmParamTypes.reserve(this->getParameterCount() + 1);
		for (size_t i = 0; i < this->getParameterCount(); ++i)
		{
			Type *paramType = paramTypes[i];
			llvmParamTypes.push_back(paramType->getLLVMType(context));
		}
		Type *myReturnType = this->getReturnType(instCtx);
		llvm::FunctionType *funcType = llvm::FunctionType::get(myReturnType->getLLVMType(context), llvmParamTypes, this->runtimeVarargs);
		//创建函数声明
		wstring funcName;
		if (this->program->getFunctions(this->name).size() > 1) {
			funcName = this->getMangledFunctionName(instCtx);
		}
		else {
			funcName = this->name;
		}

		llvm::Function *func = llvm::Function::Create(funcType,
			llvm::Function::ExternalLinkage,
			Locale::unicodeToANSI(funcName),
			context->getLLVMModule()
		);
		//添加函数参数名
		//参数名为@0,@1...
		auto itArg = func->arg_begin();
		for (size_t i = 0; i < llvmParamTypes.size(); ++i) {
			itArg->setName(Locale::unicodeToUTF8(L"@" + to_wstring(i)));
			++itArg;
		}
		this->llvmFunctions.emplace_back(paramTypes, func);
		matchedFunc = func;
		if (!declareOnly)this->generateLLVMIR(context);
	}
	return matchedFunc;
}

void WorkScript::Function::setReturnType(Type * returnType)
{
	this->abstractType = program->getFunctionType(this->abstractType->getParameterTypes(), returnType);
}

MatchResult WorkScript::Function::matchByParameters(const std::vector<Type*>& declParamTypes, const std::vector<Type*>& realParamTypes)
{
	bool compromised = false;
	size_t paramCount = declParamTypes.size();
	if (paramCount != realParamTypes.size())return MISMATCHED;
	for (size_t i = 0; i < paramCount; ++i)
	{
		Type *formalParamType = declParamTypes[i];
		if (!realParamTypes[i])continue;
		if (formalParamType && !formalParamType->equals(realParamTypes[i])) {
			if (Type::convertableTo(realParamTypes[i], formalParamType)) compromised = true;
			else return MISMATCHED;
		}
	}
	return compromised ? COMPROMISE_MATCHED : MATCHED;
}

MatchResult WorkScript::Function::matchByParameters(const std::vector<Type*> &paramTypes)
{
	auto declParamTypes = this->abstractType->getParameterTypes();
	return Function::matchByParameters(declParamTypes, paramTypes);
}

inline std::vector<Type*> WorkScript::Function::getParameterTypes(InstantializeContext * context) const
{
	auto declParamTypes = this->abstractType->getParameterTypes();
	if (!context)return declParamTypes;
	vector<Type*> realParamTypes;
	size_t paramCount = this->getParameterCount();
	realParamTypes.reserve(paramCount);
	for (size_t i = 0; i < paramCount; ++i)
	{
		wstring curParamName = Function::getStdParameterName(i);
		SymbolInfo *info = context->getSymbolInfo(curParamName);
		if (!info) {
			if (i == 0) { 
				realParamTypes = declParamTypes;
				break; 
			}
			else {
				//TODO 函数包含Location信息
				throw WorkScriptException(Location(), L"参数不匹配！");
			}
		}
		else {
			realParamTypes.push_back(info->getType());
		}
	}

	std::vector<Type*> result;
	result.reserve(paramCount);
	for (size_t i = 0; i < paramCount; ++i) {
		if (declParamTypes[i] == nullptr) {
			result.push_back(realParamTypes[i]);
		}
		else if (realParamTypes[i]->convertableTo(declParamTypes[i])) {
			result.push_back(declParamTypes[i]);
		}
		else {
			//TODO Location信息
			throw WorkScriptException(Location(), L"参数类型不匹配！");
		}
	}
	return result;
}

bool WorkScript::ParamTypesAndLLVMFunction::match(std::vector<Type*> paramTypes)
{
	for (size_t i = 0; i < this->parameterTypes.size(); ++i)
	{
		if (!this->parameterTypes[i]->equals(paramTypes[i]))return false;
	}
	return true;
}
