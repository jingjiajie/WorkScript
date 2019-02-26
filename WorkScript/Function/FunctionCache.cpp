#include "FunctionCache.h"
#include "Function.h"
#include "FunctionType.h"

using namespace WorkScript;
using namespace std;

void FunctionCache::cacheFunctionType(const WorkScript::DebugInfo &d, WorkScript::Function *func,
									  WorkScript::FunctionType *type, const WorkScript::CancelException &ex) noexcept
{
	if (this->functionTypeCache.find(func) == this->functionTypeCache.end())
	{
		this->functionTypeCache[func] = decltype(this->functionTypeCache)::mapped_type();
	}
	vector<FunctionTypeCacheItem> &items = this->functionTypeCache[func];
	bool found = false;
	for (size_t i = 0; i < items.size(); ++i)
	{
		if (items[i].matchExact(d, FunctionTypeQuery(type->getParameterTypes(), type->isConst(), type->isRumtimeVarargs())))
		{
			items[i].setFunctionType(type);
			items[i].setCancelException(ex);
			found = true;
			break;
		}
	}
	if (!found)
	{
		items.push_back(FunctionTypeCacheItem(type,ex));
	}
}

void FunctionCache::cacheFunctionType(const WorkScript::DebugInfo &d,
                                      Function *func,
                                      WorkScript::FunctionType *type) noexcept
{
	if (this->functionTypeCache.find(func) == this->functionTypeCache.end())
	{
		this->functionTypeCache[func] = decltype(this->functionTypeCache)::mapped_type();
	}
	vector<FunctionTypeCacheItem> &items = this->functionTypeCache[func];
	bool found = false;
	for (size_t i = 0; i < items.size(); ++i)
	{
		if (items[i].matchExact(d, FunctionTypeQuery(type->getParameterTypes(), type->isConst(), type->isRumtimeVarargs())))
		{
			items[i].setFunctionType(type);
			found = true;
			break;
		}
	}
	if (!found)
	{
		items.push_back(FunctionTypeCacheItem(type));
	}
}

bool FunctionCache::getCachedFunctionType(const DebugInfo &d,
										  Function *func,
										  const FunctionTypeQuery &query,
										  FunctionType **outType) const
{
	const auto &it = this->functionTypeCache.find(func);
	if (it == this->functionTypeCache.end())
	{
		return false;
	}
	const vector<FunctionTypeCacheItem> &caches = it->second;
	for (size_t i = 0; i < caches.size(); ++i)
	{
		auto &cur = caches[i];
		if (cur.matchExact(d, query))
		{
			*outType = cur.getFunctionType();
			return true;
		}
	}
	return false;
}

bool FunctionTypeCacheItem::matchExact(const WorkScript::DebugInfo &d, const WorkScript::FunctionTypeQuery &query) const noexcept
{
	return this->functionType->matchExact(d,query);
}

bool StubCacheItem::matchExact(const WorkScript::DebugInfo &d, const WorkScript::FunctionTypeQuery &query) const noexcept
{
	return this->functionType->matchExact(d,query);
}

void FunctionCache::cacheStub(const WorkScript::DebugInfo &d, WorkScript::FunctionFragment *fragment,
							  WorkScript::FunctionType *type, llvm::Function *stub) noexcept
{
	if (this->stubCache.find(fragment) == this->stubCache.end())
	{
		this->stubCache[fragment] = decltype(this->stubCache)::mapped_type();
	}
	vector<StubCacheItem> &items = this->stubCache[fragment];
	bool found = false;
	for (size_t i = 0; i < items.size(); ++i)
	{
		if (items[i].matchExact(d, FunctionTypeQuery(type->getParameterTypes(), type->isConst(), type->isRumtimeVarargs())))
		{
			items[i].setStub(stub);
			found = true;
			break;
		}
	}
	if (!found)
	{
		items.push_back(StubCacheItem(type, stub));
	}
}

bool FunctionCache::getCachedStub(const DebugInfo &d, FunctionFragment *fragment,
								  const FunctionTypeQuery &query, llvm::Function **outStub) const
{
	const auto &it = this->stubCache.find(fragment);
	if (it == this->stubCache.end())
	{
		return false;
	}
	const vector<StubCacheItem> &caches = it->second;
	for (size_t i = 0; i < caches.size(); ++i)
	{
		auto &cur = caches[i];
		if (cur.matchExact(d, query))
		{
			*outStub = cur.getStub();
			return true;
		}
	}
	return false;
}