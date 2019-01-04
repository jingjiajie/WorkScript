#include "stdafx.h"
#include "InstantializeContext.h"
#include "SymbolInfo.h"
#include "SymbolTable.h"
#include "WorkScriptException.h"
#include "Function.h"
#include "FunctionCache.h"
#include "AbstractContext.h"

using namespace WorkScript;
using namespace std;

SymbolInfo * WorkScript::InstantializeContext::getSymbolInfo(const std::wstring & name)
{
	SymbolInfo *info = this->abstractContext->getSymbolInfo(name);
	if (info) return info;
	if (this->instanceSymbolTable) {
		SymbolInfo *info = this->instanceSymbolTable->getSymbolInfo(name);
		if (info) return info;
	}
	return nullptr;
}

void WorkScript::InstantializeContext::setFunctionTypeCache(Function *func, const std::vector<Type*>& paramTypes, Type * cacheReturnType)
{
	if (!this->functionCache)
	{
		throw WorkScriptException(L"δָ��������������");
	}
	this->functionCache->setFunctionTypeCache(func, paramTypes, cacheReturnType);
}

bool WorkScript::InstantializeContext::getFunctionTypeCache(Function *func, const std::vector<Type*>& paramTypes, Type ** outReturnType)
{
	if (!this->functionCache)
	{
		throw WorkScriptException(L"δָ��������������");
	}
	return this->functionCache->getFunctionTypeCache(func, paramTypes, outReturnType);
}
