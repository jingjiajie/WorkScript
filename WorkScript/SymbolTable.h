#pragma once
#include "stdafx.h"
#include "SymbolInfo.h"

namespace WorkScript {
	class Type;
	class SymbolTable
	{
	public:
		SymbolTable();
		~SymbolTable();

		SymbolInfo * getSymbolInfo(const std::wstring &name);
		SymbolInfo * setSymbol(const std::wstring &name, Type *type);
		inline void clear() { this->symbols.clear(); }
	private:
		std::unordered_map<std::wstring, SymbolInfo> symbols;
	};
}