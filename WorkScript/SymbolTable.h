#pragma once
#include "stdafx.h"
#include "SymbolInfo.h"

namespace WorkScript {
	class Type;
	class SymbolTable
	{
	public:
		SymbolTable() {}

		virtual SymbolInfo * getSymbolInfo(const std::wstring &name);
		virtual SymbolInfo * setSymbol(const std::wstring &name, Type *type);
		inline void clear() { this->symbols.clear(); }
	protected:
		std::unordered_map<std::wstring, SymbolInfo> symbols;
	};

	class BlockSymbolTable : public SymbolTable
	{
	public:
		BlockSymbolTable(size_t blockID) :blockID(blockID) {}

		SymbolInfo * setSymbol(const std::wstring &name, Type *type);
	protected:
		size_t blockID;
	};
}