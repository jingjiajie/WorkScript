#include <unordered_map>
#include "AbstractContext.h"
#include "Function.h"
#include "IntegerType.h"
#include "FloatType.h"
#include "PointerType.h"
#include "FunctionType.h"
#include "Constant.h"

using namespace WorkScript;
using namespace std;

WorkScript::AbstractContext::AbstractContext(AbstractContext * base, size_t blockID)
	:base(base),blockID(blockID), prefix(base?base->prefix + L"." + to_wstring(blockID):L""), abstractSymbolTable(prefix)
{
//	this->addType(L"char", IntegerType::getSInt8Type());
//	this->addType(L"short", IntegerType::getSInt16Type());
//	this->addType(L"int", IntegerType::getSInt32Type());
//	this->addType(L"long", IntegerType::getSInt64Type());
//	this->addType(L"bool", IntegerType::getUInt1Type());
//	this->addType(L"unsigned char", IntegerType::getUInt8Type());
//	this->addType(L"unsigned short", IntegerType::getUInt16Type());
//	this->addType(L"unsigned int", IntegerType::getUInt32Type());
//	this->addType(L"unsigned long", IntegerType::getUInt64Type());
//	this->addType(L"float", FloatType::getFloat32Type());
//	this->addType(L"double", FloatType::getFloat64Type());
//	this->addType(L"void", VoidType::get());
}

WorkScript::AbstractContext::~AbstractContext()
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
		Type *type = itType.second;
		if (type->getClassification() == TypeClassification::CLASS) {
			delete type;
		}
	}
}

void WorkScript::AbstractContext::addFunction(Function * func)
{
	wstring name = func->getName();
	this->functions[name].push_back(func);
}

Function * WorkScript::AbstractContext::getFirstFunction(const std::wstring & name, std::vector<Type*> paramTypes)
{
	auto it = this->functions.find(name);
	Function *compromiseFunction = nullptr;
	if (it != this->functions.end()) {
		vector<Function*> functions = it->second;
		for (size_t i = 0; i < functions.size(); ++i)
		{
			MatchResult res = functions[i]->matchByParameters(paramTypes);
			switch (res)
			{
				case WorkScript::MATCHED:
					return functions[i];
				case WorkScript::COMPROMISE_MATCHED:
				{
					if (!compromiseFunction) compromiseFunction = functions[i];
					break;
				}
				default:
					break;
			}
		}
	}
	if (!compromiseFunction && base) compromiseFunction = base->getFirstFunction(name,paramTypes);
	return compromiseFunction;
}

std::vector<Function*> WorkScript::AbstractContext::getLocalFunctions(const std::wstring & name, std::vector<Type*> paramTypes, bool compromise)
{
	std::vector<Function*> result;
	auto it = this->functions.find(name);
	if (it != this->functions.end()) {
		vector<Function*> functions = it->second;
		for (size_t i = 0; i < functions.size(); ++i)
		{
			MatchResult res = functions[i]->matchByParameters(paramTypes);
			if (res == MatchResult::MATCHED || (compromise && res == MatchResult::COMPROMISE_MATCHED)) {
				result.push_back(functions[i]);
			}
		}
	}
	return result;
}

std::vector<Function*> WorkScript::AbstractContext::getLocalFunctions(const std::wstring & name)
{
	auto it = this->functions.find(name);
	if (it == this->functions.end()) {
		return std::vector<Function*>();
	}
	else {
		return it->second;
	}
}

std::vector<Function*> WorkScript::AbstractContext::getFunctions(const std::wstring & name, std::vector<Type*> paramTypes, bool compromise)
{
	auto result = this->getLocalFunctions(name, paramTypes, compromise);
	if (base) {
		auto baseFuncs = base->getFunctions(name, paramTypes, compromise);
		std::copy(baseFuncs.begin(), baseFuncs.end(), result.end());
	}
	return result;
}

std::vector<Function*> WorkScript::AbstractContext::getFunctions(const std::wstring & name)
{
	auto result = this->getLocalFunctions(name);
	if (base) {
		auto baseFuncs = base->getFunctions(name);
		std::copy(baseFuncs.begin(), baseFuncs.end(), result.end());
	}
	return result;
}


Type * WorkScript::AbstractContext::getType(const std::wstring & name, size_t pointerLevel)
{
	auto type = this->getLocalType(name, pointerLevel);
	if (!type && base) {
		type = base->getType(name, pointerLevel);
	}
	return type;
}

Type * AbstractContext::getLocalType(const std::wstring & name, size_t pointerLevel)
{
	Type *returnType = nullptr;
	auto it = this->types.find(name);
	if (it == this->types.end()) returnType = nullptr;
	else returnType = it->second;

	if (pointerLevel > 0) {
		returnType = PointerType::get(returnType, pointerLevel);
	}
	return returnType;
}

void AbstractContext::addType(const std::wstring &name, Type *type)
{
	this->types[name] = type;
}

void AbstractContext::addType(Type * type)
{
	this->addType(type->getName(), type);
}