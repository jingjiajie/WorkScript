#include "SymbolTable.h"
#include "Value.h"

using namespace WorkScript;
using namespace std;

const SymbolInfo * WorkScript::SymbolTable::getSymbolInfo(const std::wstring & name) const noexcept
{
    return const_cast<SymbolTable*>(this)->getSymbolInfo(name);
}

SymbolInfo * WorkScript::SymbolTable::getSymbolInfo(const std::wstring & name) noexcept
{
    auto it = this->symbols.find(name);
    if (it == this->symbols.end())return nullptr;
    else return &it->second;
}

SymbolInfo * WorkScript::SymbolTable::setSymbol(const DebugInfo &d, const std::wstring & name, Type * type, const LinkageType &lt, Value *value) noexcept
{
	return &(this->symbols[name] = SymbolInfo(d, this->prefix + name, type, lt, value));
}
