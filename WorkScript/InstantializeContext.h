#pragma once
#include <vector>
#include <memory>

namespace WorkScript {
	class SymbolTable;
	class SymbolInfo;
	class Type;
	class Function;
	class FunctionCache;
	class AbstractContext;

	class InstantializeContext {
	public:
		inline InstantializeContext(AbstractContext *abstractContext, FunctionCache *cache, SymbolTable *instanceSymbolTable = nullptr)
			:abstractContext(abstractContext),
			instanceSymbolTable(instanceSymbolTable),
			functionCache(cache) {}

		inline InstantializeContext(const InstantializeContext &c)
			: abstractContext(c.abstractContext),
			instanceSymbolTable(c.instanceSymbolTable),
			functionCache(c.functionCache) {}

		inline void setAbstractContext(AbstractContext *ctx) { this->abstractContext = ctx; }
		inline SymbolTable * getInstanceSymbolTable() { return this->instanceSymbolTable; }
		inline void setInstanceSymbolTable(SymbolTable *table) { this->instanceSymbolTable = table; }

		SymbolInfo * getSymbolInfo(const std::wstring &name);

		void setFunctionTypeCache(Function *func, const std::vector<Type*> &paramTypes, Type *cacheReturnType);
		bool getFunctionTypeCache(Function *func, const std::vector<Type*> &paramTypes, Type **outReturnType);
	protected:
		AbstractContext * abstractContext = nullptr;
		SymbolTable * instanceSymbolTable = nullptr;
		FunctionCache *functionCache = nullptr;
	};
}