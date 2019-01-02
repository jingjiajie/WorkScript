#include "stdafx.h"
#include "Program.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "PointerType.h"
#include "VoidType.h"
#include "FunctionType.h"
#include "Function.h"

using namespace std;
using namespace WorkScript;

VoidType Program::voidType(nullptr);

IntegerType Program::sint8(nullptr, L"sint8", 8, true);
IntegerType Program::sint16(nullptr, L"sint16", 16, true);
IntegerType Program::sint32(nullptr, L"sint32", 32, true);
IntegerType Program::sint64(nullptr, L"sint64", 64, true);
IntegerType Program::uint1(nullptr, L"uint1", 1, false);
IntegerType Program::uint8(nullptr, L"uint8", 8, false);
IntegerType Program::uint16(nullptr, L"uint16", 16, false);
IntegerType Program::uint32(nullptr, L"uint32", 32, false);
IntegerType Program::uint64(nullptr, L"uint64", 64, false);

FloatType Program::float32(nullptr, L"float32", 32);
FloatType Program::float64(nullptr, L"float64", 64);

PointerType Program::sint8ptr(nullptr, L"sint8ptr", &Program::sint8);
PointerType Program::sint16ptr(nullptr, L"sint16ptr", &Program::sint16);
PointerType Program::sint32ptr(nullptr, L"sint32ptr", &Program::sint32);
PointerType Program::sint64ptr(nullptr, L"sint64ptr", &Program::sint64);
PointerType Program::uint1ptr(nullptr, L"uint1ptr", &Program::uint1);
PointerType Program::uint8ptr(nullptr, L"uint8ptr", &Program::uint8);
PointerType Program::uint16ptr(nullptr, L"uint16ptr", &Program::uint16);
PointerType Program::uint32ptr(nullptr, L"uint32ptr", &Program::uint32);
PointerType Program::uint64ptr(nullptr, L"uint64ptr", &Program::uint64);

PointerType Program::float32ptr(nullptr, L"float32ptr", &Program::float32);
PointerType Program::float64ptr(nullptr, L"float64ptr", &Program::float64);

Program::Program()
{

}

Program::~Program()
{
	for (auto itFuncs : this->functions)
	{
		for (auto itFunc : itFuncs.second)
		{
			delete itFunc;
		}
	}
	for (auto itType : this->types) 
	{
		delete itType.second;
	}
}

//Type * WorkScript::Program::getType(const std::wstring & name) const
//{
//	auto it = this->types.find(name);
//	if (it == this->types.end()) return nullptr;
//	else return it->second;
//}
//
//void WorkScript::Program::addType(Type * abstractType)
//{
//	this->types[abstractType->getName()] = abstractType;
//}

void WorkScript::Program::generateLLVMIR(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule)
{
	GenerateContext ctx(llvmContext, llvmModule, nullptr);
	InstantializeContext funcInstCtx(0, &this->globalSymbolTable);
	ctx.setInstantializeContext(&funcInstCtx);
	Function *funcMain = this->getFirstFunction(L"main", {});
	funcMain->generateLLVMIR(&ctx);
}

void WorkScript::Program::addFunction(Function * func)
{
	wstring name = func->getName();
	this->functions[name].push_back(func);
}

Function * WorkScript::Program::getFirstFunction(const std::wstring & name, std::vector<Type*> paramTypes)
{
	auto it = this->functions.find(name);
	if (it == this->functions.end())return nullptr;
	vector<Function*> functions = it->second;
	for (size_t i = 0; i < functions.size(); ++i)
	{
		if (functions[i]->matchByParameters(paramTypes)) {
			return functions[i];
		}
	}
	return nullptr;
}

std::vector<Function*> WorkScript::Program::getFunctions(const std::wstring & name, std::vector<Type*> paramTypes)
{
	std::vector<Function*> result;
	auto it = this->functions.find(name);
	if (it == this->functions.end())return result;
	vector<Function*> functions = it->second;
	for (size_t i = 0; i < functions.size(); ++i)
	{
		if (functions[i]->matchByParameters(paramTypes)) {
			result.push_back(functions[i]);
		}
	}
	return result;
}

FunctionType * WorkScript::Program::getFunctionType(std::vector<Type*> paramTypes, Type * returnType)
{
	wstring typeName = FunctionType::getName(paramTypes, returnType);
	auto it = this->types.find(typeName);
	if (it != this->types.end()) {
		return (FunctionType*)it->second;
	}
	FunctionType *funcType = new FunctionType(this, paramTypes, returnType);
	this->types[funcType->getName()] = funcType;
	return funcType;
}
