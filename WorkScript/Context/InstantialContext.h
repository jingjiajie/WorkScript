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

	typedef unsigned BlockAttributeSetType;
	enum class BlockAttribute : BlockAttributeSetType {
		 SFINAE = 0x01
	};

	class InstantialContext {
	public:
		inline InstantialContext(AbstractContext *abstractContext, FunctionCache *cache, SymbolTable *instanceSymbolTable, unsigned long long blockAttributes = 0x00) noexcept
			:abstractContext(abstractContext),
			instanceSymbolTable(instanceSymbolTable),
			functionCache(cache),
			blockAttributes(blockAttributes)
		{ }

		inline InstantialContext(const InstantialContext *base, SymbolTable *instanceSymbolTable) noexcept
			:abstractContext(base->abstractContext),
			functionCache(base->functionCache),
			blockAttributes(base->blockAttributes),
			instanceSymbolTable(instanceSymbolTable)
		{ }

		inline void setAbstractContext(AbstractContext *ctx) noexcept { this->abstractContext = ctx; }
		inline SymbolTable * getInstanceSymbolTable() noexcept { return this->instanceSymbolTable; }
		inline void setInstanceSymbolTable(SymbolTable *table) noexcept { this->instanceSymbolTable = table; }
		inline FunctionCache *getFunctionCache() noexcept { return this->functionCache; }

		const SymbolInfo * getSymbolInfo(const std::wstring &name) const noexcept;
		SymbolInfo * getSymbolInfo(const std::wstring &name) noexcept;

		void cacheFunctionType(const DebugInfo &d, Function *func, FunctionType *type) noexcept;
		bool getCachedFunctionType(const DebugInfo &d, Function *func, const FunctionTypeQuery &query,
									 FunctionType **outType) const noexcept;
		
		inline void setBlockAttribute(BlockAttribute attr, bool enable) noexcept{
			BlockAttributeSetType a = (BlockAttributeSetType)attr;
			this->blockAttributes = enable ? blockAttributes | a : blockAttributes & ~a;
		}

		inline bool getBlockAttribute(BlockAttribute attr) const noexcept{
			return this->blockAttributes & (BlockAttributeSetType)attr;
		}
	protected:
		AbstractContext * abstractContext = nullptr;
		SymbolTable * instanceSymbolTable = nullptr;
		FunctionCache *functionCache = nullptr;
		BlockAttributeSetType blockAttributes = 0;
	};
}
