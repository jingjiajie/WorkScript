#include "InstantialContext.h"
#include "SymbolInfo.h"
#include "SymbolTable.h"
#include "ErrorManager.h"
#include "Function.h"
#include "FunctionCache.h"
#include "AbstractContext.h"
#include "Constant.h"

using namespace WorkScript;
using namespace std;

SymbolInfo * InstantialContext::getSymbolInfo(const std::wstring & name)
{
	SymbolInfo *info = this->abstractContext->getSymbolInfo(name);
	if (info) return info;
	if (this->instanceSymbolTable) {
		SymbolInfo *info = this->instanceSymbolTable->getSymbolInfo(name);
		if (info) return info;
	}
	return nullptr;
}

void InstantialContext::setFunctionTypeCache(const DebugInfo &d, WorkScript::Function *func,
                                                const std::vector<WorkScript::Type *> &paramTypes,
                                                bool isRuntimeVarargs, bool isStaticVarargs,
                                                WorkScript::Type *cacheReturnType)
{
    if (!this->functionCache)
    {
        throw WorkScriptException(d, L"未指定函数缓存器！");
    }
    this->functionCache->setFunctionTypeCache(d, func, paramTypes, isRuntimeVarargs, isStaticVarargs, cacheReturnType);
}

bool InstantialContext::getFunctionTypeCache(const DebugInfo &d, Function *func, const std::vector<Type*>& paramTypes, bool isRuntimeVarargs, bool isStaticVarargs, Type ** outReturnType)
{
	if (!this->functionCache)
	{
		throw WorkScriptException(d, L"未指定函数缓存器！");
	}
	return this->functionCache->getFunctionTypeCache(d, func, paramTypes, isRuntimeVarargs, isStaticVarargs, outReturnType);
}
