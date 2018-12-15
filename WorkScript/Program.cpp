#include "stdafx.h"
#include "Program.h"
#include "Function.h"
#include "FunctionTemplate.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "IntegerPointerType.h"
#include "FloatPointerType.h"
#include "VoidType.h"

using namespace std;
using namespace WorkScript;

VoidType Program::voidType(nullptr);

IntegerType Program::sint8(nullptr, L"sint8", 8, true);
IntegerType Program::sint16(nullptr, L"sint16", 16, true);
IntegerType Program::sint32(nullptr, L"sint32", 32, true);
IntegerType Program::sint64(nullptr, L"sint64", 64, true);
IntegerType Program::uint1(nullptr, L"uint1", 1, true);
IntegerType Program::uint8(nullptr, L"uint8", 8, true);
IntegerType Program::uint16(nullptr, L"uint16", 16, true);
IntegerType Program::uint32(nullptr, L"uint32", 32, true);
IntegerType Program::uint64(nullptr, L"uint64", 64, true);

FloatType Program::float32(nullptr, L"float32", 32);
FloatType Program::float64(nullptr, L"float64", 64);

IntegerPointerType Program::sint8ptr(nullptr, L"sint8ptr", 8, true);
IntegerPointerType Program::sint16ptr(nullptr, L"sint16ptr", 16, true);
IntegerPointerType Program::sint32ptr(nullptr, L"sint32ptr", 32, true);
IntegerPointerType Program::sint64ptr(nullptr, L"sint64ptr", 64, true);
IntegerPointerType Program::uint1ptr(nullptr, L"uint1ptr", 1, true);
IntegerPointerType Program::uint8ptr(nullptr, L"uint8ptr", 8, true);
IntegerPointerType Program::uint16ptr(nullptr, L"uint16ptr", 16, true);
IntegerPointerType Program::uint32ptr(nullptr, L"uint32ptr", 32, true);
IntegerPointerType Program::uint64ptr(nullptr, L"uint64ptr", 64, true);

FloatPointerType Program::float32ptr(nullptr, L"float32ptr", 32);
FloatPointerType Program::float64ptr(nullptr, L"float64ptr", 64);

Program::Program()
{
}

Program::~Program()
{
	for (auto itFunc : this->functions)
	{
		delete itFunc.second;
	}
	for (auto itFuncTemplate : this->functionTemplates)
	{
		delete itFuncTemplate.second;
	}
}
Overload * WorkScript::Program::getFunctionOverload(const std::wstring &funcName, const std::vector<Type*> &paramTypes)
{
	auto it = this->functions.find(funcName);
	Function *func;
	FunctionTemplate *funcTemplate;
	//获取相应模板
	auto itTemplate = this->functionTemplates.find(funcName);
	if (itTemplate == this->functionTemplates.end()) {
		funcTemplate = nullptr;
	}
	else {
		funcTemplate = itTemplate->second;
	}
	//获取函数
	if (it != this->functions.end())
	{
		func = it->second;
	}
	else {
		if (!funcTemplate) return nullptr;
		func = funcTemplate->createFunction();
		this->addFunction(func);
	}
	//获取重载
	Overload *overload = func->getOverload(paramTypes);
	if (!overload) {
		if (!funcTemplate)return nullptr;
		OverloadTemplate *overloadTemplate = funcTemplate->getOverload(paramTypes);
		if (!overloadTemplate)return nullptr;
		overload = overloadTemplate->createOverload(func, paramTypes);
		func->addOverload(overload);
	}
	return overload;
}

void WorkScript::Program::addFunction(Function * func)
{
	this->functions[func->getName()] = func;
}

FunctionTemplate * WorkScript::Program::getFunctionTemplate(const std::wstring & funcName) const
{
	auto it = this->functionTemplates.find(funcName);
	if (it == this->functionTemplates.end())return nullptr;
	else return it->second;
}

void WorkScript::Program::addFunctionTemplate(FunctionTemplate *funcTemplate, Type *type)
{
	this->functionTemplates[funcTemplate->getName()] = funcTemplate;
}

//Type * WorkScript::Program::getType(const std::wstring & name) const
//{
//	auto it = this->types.find(name);
//	if (it == this->types.end()) return nullptr;
//	else return it->second;
//}
//
//void WorkScript::Program::addType(Type * type)
//{
//	this->types[type->getName()] = type;
//}

void WorkScript::Program::generateLLVMIR(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule)
{
	GenerateContext ctx(llvmContext, llvmModule, nullptr);
	for (auto it : this->functions) {
		Function *f = it.second;
		f->generateLLVMIR(&ctx);
	}
}