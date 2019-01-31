#pragma once
#include <vector>
#include <memory>
#include "DebugInfo.h"

namespace WorkScript {
	class SymbolTable;
	class SymbolInfo;
	class Type;
	class Function;
	class FunctionCache;
	class AbstractContext;

	class InstantialContext {
	public:
		inline InstantialContext(AbstractContext *abstractContext, FunctionCache *cache, SymbolTable *instanceSymbolTable = nullptr)
			:abstractContext(abstractContext),
			instanceSymbolTable(instanceSymbolTable),
			functionCache(cache) {}

		inline InstantialContext(const InstantialContext &c)
			: abstractContext(c.abstractContext),
			instanceSymbolTable(c.instanceSymbolTable),
			functionCache(c.functionCache) {}

		inline void setAbstractContext(AbstractContext *ctx) { this->abstractContext = ctx; }
		inline SymbolTable * getInstanceSymbolTable() { return this->instanceSymbolTable; }
		inline void setInstanceSymbolTable(SymbolTable *table) { this->instanceSymbolTable = table; }

		SymbolInfo * getSymbolInfo(const std::wstring &name);

		void setFunctionTypeCache(const DebugInfo &d, Function *func, const std::vector<Type*> &paramTypes, bool isRuntimeVarargs, bool isStaticVarargs, Type *cacheReturnType);
		bool getFunctionTypeCache(const DebugInfo &d, Function *func, const std::vector<Type*> &paramTypes, bool isRuntimeVarargs, bool isStaticVarargs, Type **outReturnType);
	protected:
		AbstractContext * abstractContext = nullptr;
		SymbolTable * instanceSymbolTable = nullptr;
		FunctionCache *functionCache = nullptr;
	};
}