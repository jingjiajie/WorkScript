#include "SymbolTable.h"
#include "Value.h"
#include "GeneralSymbolInfo.h"
#include "ReferenceSymbolInfo.h"

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
    else return it->second;
}



SymbolInfo * SymbolTable::setSymbol(const DebugInfo &d, const std::wstring & name, Type * type, const LinkageType &lt, Value *value) noexcept
{
    auto &info = this->symbols[name];
    delete info;
    info = new GeneralSymbolInfo(d, this->prefix + name, type, lt, value);
	return info;
}

SymbolInfo *SymbolTable::setSymbol(const DebugInfo &d, const wstring &name, SymbolInfo *refSymbolInfo)
{
    auto &info = this->symbols[name];
    delete info;
    info = new ReferenceSymbolInfo(d, this->prefix + name, refSymbolInfo);
    return info;
}
