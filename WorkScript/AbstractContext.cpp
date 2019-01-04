#include "stdafx.h"
#include "AbstractContext.h"

using namespace WorkScript;
using namespace std;

BlockSymbolTable * WorkScript::BlockAbstractContext::getAbstractSymbolTable()
{
	return &this->abstractSymbolTable;
}

SymbolTable * WorkScript::CommonAbstractContext::getAbstractSymbolTable()
{
	return &this->abstractSymbolTable;
}
