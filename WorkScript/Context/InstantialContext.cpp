#include "InstantialContext.h"
#include "SymbolInfo.h"
#include "SymbolTable.h"
#include "Report.h"
#include "Exception.h"
#include "Function.h"
#include "FunctionCache.h"
#include "AbstractContext.h"
#include "Value.h"

using namespace WorkScript;
using namespace std;

const SymbolInfo * InstantialContext::getSymbolInfo(const std::wstring & name) const noexcept
{
    return const_cast<InstantialContext*>(this)->getSymbolInfo(name);
}

SymbolInfo *InstantialContext::getSymbolInfo(const std::wstring &name) noexcept
{
    SymbolInfo *info = this->abstractContext->getSymbolInfo(name);
    if (info) return info;
    else if (this->instanceSymbolTable) {
        return this->instanceSymbolTable->getSymbolInfo(name);
    }
    return nullptr;
}


void InstantialContext::cacheFunctionType(const WorkScript::DebugInfo &d,
												  WorkScript::Function *func,
												  WorkScript::FunctionType *type) noexcept
{
    this->functionCache->cacheFunctionType(d, func, type);
}

bool InstantialContext::getCachedFunctionType(const WorkScript::DebugInfo &d,
                                                Function *func,
												const WorkScript::FunctionTypeQuery &query,
												WorkScript::FunctionType **outType) const noexcept
{
	return this->functionCache->getCachedFunctionType(d, func, query, outType);
}