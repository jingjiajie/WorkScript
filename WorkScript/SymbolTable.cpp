#include "stdafx.h"
#include "SymbolTable.h"

using namespace WorkScript;
using namespace std;

SymbolTable::SymbolTable()
{
}


SymbolTable::~SymbolTable()
{
}

const SymbolInfo * WorkScript::SymbolTable::getSymbolInfo(const std::wstring & name) const
{
	auto it = this->symbols.find(name);
	if (it == this->symbols.end())return nullptr;
	else return &this->symbols.at(name);
}

void WorkScript::SymbolTable::setSymbol(const std::wstring & name, Type * type)
{
	this->symbols[name].setType(type);
}
