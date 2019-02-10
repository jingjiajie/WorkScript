#pragma once
#include <unordered_map>
#include <vector>
#include "DebugInfo.h"

namespace WorkScript {
	class Function;
	class Type;
	class FunctionType;
    class FunctionTypeQuery;

	class FunctionCache {
	public:
		void cacheFunctionType(const DebugInfo &d, Function *func, FunctionType *type) noexcept;
		bool getCachedFunctionType(const DebugInfo &d, Function *func, const FunctionTypeQuery &query,
                                   FunctionType **outType) const noexcept;
	
	protected:
		std::unordered_map<Function*, std::vector<FunctionType*>> cache;
	};
}