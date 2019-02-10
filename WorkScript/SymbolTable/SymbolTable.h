#pragma once
#include <unordered_map>
#include "SymbolInfo.h"

namespace WorkScript {
	class Type;
	class SymbolTable
	{
	public:
		SymbolTable(const std::wstring &prefix = L"") noexcept
			:prefix(prefix) {}

		virtual const SymbolInfo * getSymbolInfo(const std::wstring &name) const noexcept;
        virtual SymbolInfo * getSymbolInfo(const std::wstring &name) noexcept;
		virtual SymbolInfo * setSymbol(const DebugInfo &d, const std::wstring &name, Type *type,const LinkageType &lt, Value *value = nullptr) noexcept;
		inline void clear() noexcept { this->symbols.clear(); }
	protected:
		std::unordered_map<std::wstring, SymbolInfo> symbols;
		std::wstring prefix;
	};
}