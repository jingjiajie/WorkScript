#include "InstantializeContext.h"
#include "SymbolInfo.h"
#include "SymbolTable.h"
#include "WorkScriptException.h"
#include "Function.h"
#include "FunctionCache.h"
#include "AbstractContext.h"

using namespace WorkScript;
using namespace std;

SymbolInfo * InstantializeContext::getSymbolInfo(const std::wstring & name)
{
	SymbolInfo *info = this->abstractContext->getSymbolInfo(name);
	if (info) return info;
	if (this->instanceSymbolTable) {
		SymbolInfo *info = this->instanceSymbolTable->getSymbolInfo(name);
		if (info) return info;
	}
	return nullptr;
}

void InstantializeContext::setFunctionTypeCache(WorkScript::Function *func,
                                                const std::vector<WorkScript::Type *> &paramTypes,
                                                bool isRuntimeVarargs, bool isStaticVarargs,
                                                WorkScript::Type *cacheReturnType)
{
    if (!this->functionCache)
    {
        //TODO Location信息
        throw WorkScriptException(Location(), L"未指定函数缓存器！");
    }
    this->functionCache->setFunctionTypeCache(func, paramTypes, isRuntimeVarargs, isStaticVarargs, cacheReturnType);
}

bool InstantializeContext::getFunctionTypeCache(Function *func, const std::vector<Type*>& paramTypes, bool isRuntimeVarargs, bool isStaticVarargs, Type ** outReturnType)
{
	if (!this->functionCache)
	{
		//TODO Location信息
		throw WorkScriptException(Location(), L"未指定函数缓存器！");
	}
	return this->functionCache->getFunctionTypeCache(func, paramTypes, isRuntimeVarargs, isStaticVarargs, outReturnType);
}
