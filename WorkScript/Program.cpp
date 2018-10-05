#include "stdafx.h"
#include "Program.h"
#include "Function.h"
#include "FunctionTemplate.h"

using namespace std;
using namespace WorkScript;
namespace WorkScript {
	extern void initIntegerType(Program *p);
	extern void initBooleanType(Program *p);
	extern void initByteType(Program *p);
	extern void initDoubleType(Program *p);
	extern void initStringType(Program *p);
}

Program::Program()
{
	this->types[TYPENAME_INTEGER] = nullptr;
	this->types[TYPENAME_BOOLEAN] = nullptr;
	this->types[TYPENAME_BYTE] = nullptr;
	this->types[TYPENAME_DOUBLE] = nullptr;
	this->types[TYPENAME_STRING] = nullptr;
	initIntegerType(this);
	initBooleanType(this);
	initByteType(this);
	initDoubleType(this);
	initStringType(this);
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
Overload * WorkScript::Program::getFunctionOverload(const std::wstring &funcName, const std::vector<Type*> &paramTypes, Type *type)
{
	auto it = this->functions.find(make_pair(type, funcName));
	Function *func;
	FunctionTemplate *funcTemplate;
	//获取相应模板
	auto itTemplate = this->functionTemplates.find(make_pair(type, funcName));
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
		this->addFunction(func, type);
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

void WorkScript::Program::addFunction(Function * func, Type *type)
{
	this->functions[make_pair(type, func->getName())] = func;
}

FunctionTemplate * WorkScript::Program::getFunctionTemplate(const std::wstring & funcName, Type *type) const
{
	auto it = this->functionTemplates.find(make_pair(type, funcName));
	if (it == this->functionTemplates.end())return nullptr;
	else return it->second;
}

void WorkScript::Program::addFunctionTemplate(FunctionTemplate *funcTemplate, Type *type)
{
	this->functionTemplates[make_pair(type, funcTemplate->getName())] = funcTemplate;
}

Type * WorkScript::Program::getType(const std::wstring & name) const
{
	auto it = this->types.find(name);
	if (it == this->types.end()) return nullptr;
	else return it->second;
}

void WorkScript::Program::addType(Type * type)
{
	this->types[type->getName()] = type;
}
