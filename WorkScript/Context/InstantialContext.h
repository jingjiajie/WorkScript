#pragma once
#include <vector>
#include <memory>
#include "DebugInfo.h"
#include "SymbolTable.h"
#include "AbstractContext.h"

namespace WorkScript {
	class Type;
	class Function;
	class FunctionFragment;
	class FunctionType;
	class FunctionCache;
	class FunctionTypeQuery;
	class StringCache;

	typedef unsigned BlockAttribute;
	enum class BlockAttributeItem : BlockAttribute {
		 SFINAE = 0x01
	};

	class InstantialContext {
	public:
		inline InstantialContext(AbstractContext *abstractContext, FunctionCache *cache, StringCache *stringCache, BlockAttribute blockAttributes = 0x00) noexcept
			:abstractContext(abstractContext),
			functionCache(cache),
			stringCache(stringCache),
			blockAttributes(blockAttributes),
			instanceSymbolTable(abstractContext->getBlockPrefix())
		{ }

		inline InstantialContext(AbstractContext *abstractContext, const InstantialContext *base) noexcept
			:abstractContext(abstractContext),
			functionCache(base->functionCache),
			stringCache(base->stringCache),
			blockAttributes(base->blockAttributes),
			instanceSymbolTable(abstractContext->getBlockPrefix())
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

		inline StringCache * getStringCache() const noexcept{
		    return this->stringCache;
		}
	protected:
		AbstractContext * abstractContext = nullptr;
		SymbolTable instanceSymbolTable;
		FunctionCache *functionCache = nullptr;
		StringCache *stringCache = nullptr;
		BlockAttribute blockAttributes = 0;
	};
}
