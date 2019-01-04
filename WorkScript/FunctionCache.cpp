#include "stdafx.h"
#include "FunctionCache.h"
#include "Function.h"

using namespace WorkScript;
using namespace std;

void FunctionCache::setFunctionTypeCache(Function *branch, const std::vector<Type*> &paramTypes, Type * cacheReturnType)
{
	if (this->functionBranchTypeCache.find(branch) == this->functionBranchTypeCache.end()) {
		this->functionBranchTypeCache[branch] = decltype(this->functionBranchTypeCache)::mapped_type();
	}
	vector<ParameterTypesAndReturnType> &caches = this->functionBranchTypeCache[branch];
	bool found = false;
	for (size_t i = 0; i < caches.size(); ++i) {
		auto &cur = caches[i];
		if (cur.matchByParameters(paramTypes))
		{
			cur.setReturnType(cacheReturnType);
			found = true;
			break;
		}
	}
	if (!found) {
		caches.push_back(ParameterTypesAndReturnType(paramTypes, cacheReturnType));
	}
}

bool FunctionCache::getFunctionTypeCache(Function *branch, const std::vector<Type*> &paramTypes, Type **outReturnType)
{
	if (this->functionBranchTypeCache.find(branch) == this->functionBranchTypeCache.end()) {
		this->functionBranchTypeCache[branch] = decltype(this->functionBranchTypeCache)::mapped_type();
	}
	vector<ParameterTypesAndReturnType> &caches = this->functionBranchTypeCache[branch];
	for (size_t i = 0; i < caches.size(); ++i) {
		auto cur = caches[i];
		if (cur.matchByParameters(paramTypes))
		{
			*outReturnType = cur.getReturnType();
			return true;
		}
	}
	return false;
}

bool FunctionCache::ParameterTypesAndReturnType::matchByParameters(const std::vector<Type*>& paramTypes)
{
	return Function::matchByParameters(this->parameterTypes, parameterTypes);
}
