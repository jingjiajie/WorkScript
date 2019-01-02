#include "stdafx.h"
#include "SymbolTable.h"

using namespace WorkScript;
using namespace std;

SymbolInfo * WorkScript::SymbolTable::getSymbolInfo(const std::wstring & name)
{
	auto it = this->symbols.find(name);
	if (it == this->symbols.end())return nullptr;
	else return &it->second;
}

SymbolInfo * WorkScript::SymbolTable::setSymbol(const std::wstring & name, Type * type)
{
	this->symbols[name] = SymbolInfo(name, type);
	return &this->symbols[name];
}

SymbolInfo * WorkScript::BlockSymbolTable::setSymbol(const std::wstring & name, Type * type)
{
	this->symbols[name] = SymbolInfo(L"." + to_wstring(blockID) + name, type);
	return &this->symbols[name];
}
