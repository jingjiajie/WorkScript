#pragma once
#include <unordered_map>
#include <vector>
#include "DebugInfo.h"
#include "Exception.h"

#include <llvm/IR/Function.h>

namespace WorkScript {
	class Function;
	class Type;
	class FunctionType;
    class FunctionTypeQuery;
    class FunctionFragment;

    class FunctionTypeCacheItem{
    public:
		inline explicit FunctionTypeCacheItem() noexcept = default;
		inline explicit FunctionTypeCacheItem(FunctionType *t) noexcept : functionType(t){}
		inline explicit FunctionTypeCacheItem(FunctionType *t, const CancelException &ex) noexcept
			: functionType(t), cancelException(new CancelException(ex)){}
		inline ~FunctionTypeCacheItem(){ delete this->cancelException; }
		bool match(const DebugInfo &d, const FunctionTypeQuery &query) const noexcept;
		inline FunctionType *getFunctionType() const{
			if(this->cancelException) throw *this->cancelException;
			else return this->functionType;
		}

		inline void setFunctionType(FunctionType *t) noexcept{
			this->functionType = t;
		}

		inline void setCancelException(const CancelException &ex) noexcept{
			delete this->cancelException;
			this->cancelException = new CancelException(ex);
		}
	private:
    	FunctionType *functionType = nullptr;
    	CancelException *cancelException = nullptr;
    };

    class StubCacheItem
	{
	public:
		inline explicit StubCacheItem() noexcept = default;

		inline explicit StubCacheItem(FunctionType *t, llvm::Function *stub) noexcept
				: functionType(t), stub(stub)
		{};

		bool match(const DebugInfo &d, const FunctionTypeQuery &query) const noexcept;

		inline void setStub(llvm::Function *stub) noexcept
		{ this->stub = stub; }

		inline llvm::Function * getStub() const noexcept{return this->stub;}

	private:
		FunctionType *functionType = nullptr;
		llvm::Function *stub = nullptr;
	};

	class FunctionCache {
	public:
		void cacheFunctionType(const DebugInfo &d, Function *func, FunctionType *type, const CancelException &ex) noexcept;
		void cacheFunctionType(const DebugInfo &d, Function *func, FunctionType *type) noexcept;
		bool getCachedFunctionType(const DebugInfo &d, Function *func, const FunctionTypeQuery &query,
                                   FunctionType **outType) const;

		void cacheStub(const DebugInfo &d, FunctionFragment *fragment, FunctionType *type, llvm::Function *stub) noexcept;
		bool getCachedStub(const DebugInfo &d, FunctionFragment *fragment, const FunctionTypeQuery &query, llvm::Function **outStub) const;
	
	protected:
		std::unordered_map<Function*, std::vector<FunctionTypeCacheItem>> functionTypeCache;
		std::unordered_map<FunctionFragment*, std::vector<StubCacheItem>> stubCache;
	};
}
