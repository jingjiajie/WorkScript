#pragma once
#include <unordered_map>
#include <vector>
#include "DebugInfo.h"
#include "Exception.h"

namespace WorkScript {
	class Function;
	class Type;
	class FunctionType;
    class FunctionTypeQuery;

    class FunctionCacheItem{
    public:
		inline explicit FunctionCacheItem() noexcept = default;
		inline explicit FunctionCacheItem(FunctionType *t) noexcept : functionType(t){}
		inline explicit FunctionCacheItem(FunctionType *t, const CancelException &ex) noexcept
			: functionType(t), cancelException(new CancelException(ex)){}
		inline ~FunctionCacheItem(){ delete this->cancelException; }
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

	class FunctionCache {
	public:
		void cacheFunctionType(const DebugInfo &d, Function *func, FunctionType *type, const CancelException &ex) noexcept;
		void cacheFunctionType(const DebugInfo &d, Function *func, FunctionType *type) noexcept;
		bool getCachedFunctionType(const DebugInfo &d, Function *func, const FunctionTypeQuery &query,
                                   FunctionType **outType) const;
	
	protected:
		std::unordered_map<Function*, std::vector<FunctionCacheItem>> cache;
	};
}
