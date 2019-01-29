#pragma once
#include <unordered_map>
#include "SymbolInfo.h"

namespace WorkScript {
	class Type;
	class SymbolTable
	{
	public:
		SymbolTable(const std::wstring &prefix = L"")
			:prefix(prefix) {}

		virtual SymbolInfo * getSymbolInfo(const std::wstring &name);
		virtual SymbolInfo * setSymbol(const DebugInfo &d, const std::wstring &name, Type *type);
		inline void clear() { this->symbols.clear(); }
	protected:
		std::unordered_map<std::wstring, SymbolInfo> symbols;
		std::wstring prefix;
	};
}