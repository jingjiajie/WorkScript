#pragma once
#include <vector>
#include <memory>
#include "DebugInfo.h"

namespace WorkScript {
	class SymbolTable;
	class SymbolInfo;
	class Type;
	class Function;
	class FunctionFragment;
	class FunctionType;
	class FunctionCache;
	class AbstractContext;
	class FunctionTypeQuery;

	class InstantialContext {
	public:
		inline InstantialContext(AbstractContext *abstractContext, FunctionCache *cache, SymbolTable *instanceSymbolTable = nullptr) noexcept
			:abstractContext(abstractContext),
			instanceSymbolTable(instanceSymbolTable),
			functionCache(cache) {}

		inline InstantialContext(const InstantialContext &c) noexcept = default;

		inline void setAbstractContext(AbstractContext *ctx) noexcept { this->abstractContext = ctx; }
		inline SymbolTable * getInstanceSymbolTable() noexcept { return this->instanceSymbolTable; }
		inline void setInstanceSymbolTable(SymbolTable *table) noexcept { this->instanceSymbolTable = table; }
		inline FunctionCache *getFunctionCache() noexcept { return this->functionCache; }

		const SymbolInfo * getSymbolInfo(const std::wstring &name) const noexcept;
		SymbolInfo * getSymbolInfo(const std::wstring &name) noexcept;

		void cacheFunctionType(const DebugInfo &d, Function *func, FunctionType *type) noexcept;
		bool getCachedFunctionType(const DebugInfo &d, Function *func, const FunctionTypeQuery &query,
									 FunctionType **outType) const noexcept;
	protected:
		AbstractContext * abstractContext = nullptr;
		SymbolTable * instanceSymbolTable = nullptr;
		FunctionCache *functionCache = nullptr;
	};
}