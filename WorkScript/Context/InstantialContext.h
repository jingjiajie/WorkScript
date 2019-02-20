#pragma once
#include <vector>
#include <memory>
#include "DebugInfo.h"
#include "SymbolTable.h"

namespace WorkScript {
	class Type;
	class Function;
	class FunctionFragment;
	class FunctionType;
	class FunctionCache;
	class AbstractContext;
	class FunctionTypeQuery;

	typedef unsigned BlockAttribute;
	enum class BlockAttributeItem : BlockAttribute {
		 SFINAE = 0x01
	};

	class InstantialContext {
	public:
		inline InstantialContext(AbstractContext *abstractContext, FunctionCache *cache,const std::wstring &blockPrefix = L"", BlockAttribute blockAttributes = 0x00) noexcept
			:abstractContext(abstractContext),
			functionCache(cache),
			blockAttributes(blockAttributes),
			instanceSymbolTable(blockPrefix)
		{ }

		inline InstantialContext(const InstantialContext *base, const std::wstring &blockPrefix = L"") noexcept
			:abstractContext(base->abstractContext),
			functionCache(base->functionCache),
			blockAttributes(base->blockAttributes),
			instanceSymbolTable(blockPrefix)
		{ }

		inline void setAbstractContext(AbstractContext *ctx) noexcept { this->abstractContext = ctx; }
		inline SymbolTable * getInstanceSymbolTable() noexcept { return &this->instanceSymbolTable; }
		inline FunctionCache *getFunctionCache() noexcept { return this->functionCache; }

		const SymbolInfo * getSymbolInfo(const std::wstring &name) const noexcept;
		SymbolInfo * getSymbolInfo(const std::wstring &name) noexcept;

		void cacheFunctionType(const DebugInfo &d, Function *func, FunctionType *type) noexcept;
		bool getCachedFunctionType(const DebugInfo &d, Function *func, const FunctionTypeQuery &query,
									 FunctionType **outType) const;
		
		inline void setBlockAttribute(BlockAttributeItem item, bool enable) noexcept{
			auto i = (BlockAttribute)item;
			this->blockAttributes = enable ? blockAttributes | i : blockAttributes & ~i;
		}

		inline bool getBlockAttribute(BlockAttributeItem item) const noexcept{
			return (bool)(this->blockAttributes & (BlockAttribute)item);
		}
	protected:
		AbstractContext * abstractContext = nullptr;
		SymbolTable instanceSymbolTable;
		FunctionCache *functionCache = nullptr;
		BlockAttribute blockAttributes = 0;
	};
}
