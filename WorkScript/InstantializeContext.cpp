#include "stdafx.h"
#include "InstantializeContext.h"
#include "SymbolInfo.h"
#include "SymbolTable.h"
#include "WorkScriptException.h"

using namespace WorkScript;
using namespace std;

SymbolInfo * WorkScript::InstantializeContext::getSymbolInfo(const std::wstring & name)
{
	if (this->abstractSymbolTable) {
		SymbolInfo *info = this->abstractSymbolTable->getSymbolInfo(name);
		if (info) return info;
	}
	if (this->instanceSymbolTable) {
		SymbolInfo *info = this->instanceSymbolTable->getSymbolInfo(name);
		if(info) return info;
	}
	return nullptr;
}

std::vector<Type*> WorkScript::FunctionInstantializeContext::getRealParameterTypes()
{
	return this->realParameterTypes;
}
