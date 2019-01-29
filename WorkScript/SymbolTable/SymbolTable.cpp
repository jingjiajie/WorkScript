#include "SymbolTable.h"
#include "Constant.h"

using namespace WorkScript;
using namespace std;

SymbolInfo * WorkScript::SymbolTable::getSymbolInfo(const std::wstring & name)
{
	auto it = this->symbols.find(name);
	if (it == this->symbols.end())return nullptr;
	else return &it->second;
}

SymbolInfo * WorkScript::SymbolTable::setSymbol(const DebugInfo &d, const std::wstring & name, Type * type)
{
	return &(this->symbols[name] = SymbolInfo(d, this->prefix + name, type));
}
