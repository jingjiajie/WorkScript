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

SymbolInfo * SymbolTable::setSymbol(const SymbolInfo &info) noexcept
{
    auto &ori = this->symbols[info.getName()];
    delete ori;
    return ori = info.clone();
}