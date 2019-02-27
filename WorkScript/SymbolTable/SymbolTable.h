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

		virtual ~SymbolTable(){
		    for(const auto &item : symbols){
		        delete item.second;
		    }
		}

		const SymbolInfo * getSymbolInfo(const std::wstring &name) const noexcept;
        SymbolInfo * getSymbolInfo(const std::wstring &name) noexcept;
		SymbolInfo * setSymbol(const DebugInfo &d, const std::wstring &name, Type *type,const LinkageType &lt, Value *value = nullptr) noexcept;
        SymbolInfo * setSymbol(const DebugInfo &d, const std::wstring &name, SymbolInfo *refSymbolInfo);
		inline void clear() noexcept { this->symbols.clear(); }
	protected:
		std::unordered_map<std::wstring, SymbolInfo*> symbols;
		std::wstring prefix;
	};
}