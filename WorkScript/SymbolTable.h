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

		const SymbolInfo * getSymbolInfo(const std::wstring &name) const;
		void setSymbol(const std::wstring &name, Type *type);
	private:
		std::unordered_map<std::wstring, SymbolInfo> symbols;
	};
}