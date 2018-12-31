#include "stdafx.h"
#include "Function.h"
#include "Locale.h"
#include "InstantializeContext.h"
#include "FunctionType.h"

using namespace std;
using namespace WorkScript;

WorkScript::Function::Function(Program *program, const std::wstring &name, const std::vector<Type*>& paramTypes, Type * returnType)
	:program(program),name(name)
{	
	FunctionType *funcType = program->getFunctionType(paramTypes, returnType);
	this->abstractType = funcType;
}

WorkScript::Function::~Function()
{

}

std::wstring WorkScript::Function::getMangledFunctionName(FunctionInstantializeContext *ctx) const
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
	FunctionInstantializeContext *instCtx = (FunctionInstantializeContext*)context->getInstantializeContext();
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
		llvm::FunctionType *funcType = llvm::FunctionType::get(this->getReturnType(instCtx)->getLLVMType(context), llvmParamTypes, false);
		//创建函数声明
		llvm::Function *func = llvm::Function::Create(funcType,
			llvm::Function::ExternalLinkage,
			Locale::unicodeToUTF8(this->getMangledFunctionName(instCtx)),
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

bool WorkScript::Function::matchByParameters(const std::vector<Type*> &paramTypes)
{
	size_t paramCount = paramTypes.size();

	if (paramCount != this->getParameterCount())return false;
	auto myParamTypes = this->getParameterTypes(nullptr);
	for (size_t i = 0; i < paramCount; ++i)
	{
		Type *formalParamType = myParamTypes[i];
		if (formalParamType && !formalParamType->equals(paramTypes[i]))return false;
	}
	return true;
}

inline std::vector<Type*> WorkScript::Function::getParameterTypes(FunctionInstantializeContext * context) const
{
	auto declParamTypes = this->abstractType->getParameterTypes();
	if (!context)return declParamTypes;
	auto realParamTypes = context->getRealParameterTypes();
	if (realParamTypes.size() == 0)return declParamTypes;
	size_t paramCount = declParamTypes.size();
	if (paramCount != realParamTypes.size()) {
		throw WorkScriptException(L"参数个数不匹配！");
	}
	std::vector<Type*> result;
	result.reserve(paramCount);
	for (size_t i = 0; i < paramCount; ++i) {
		if (declParamTypes[i] == nullptr) {
			result.push_back(realParamTypes[i]);
		}
		else if (declParamTypes[i]->equals(realParamTypes[i])) {
			result.push_back(realParamTypes[i]);
		}
		else {
			throw WorkScriptException(L"参数类型不匹配！");
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
