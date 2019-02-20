#include "FunctionCache.h"
#include "Function.h"
#include "FunctionType.h"

using namespace WorkScript;
using namespace std;

void FunctionCache::cacheFunctionType(const WorkScript::DebugInfo &d, WorkScript::Function *func,
									  WorkScript::FunctionType *type, const WorkScript::CancelException &ex) noexcept
{
	if (this->cache.find(func) == this->cache.end())
	{
		this->cache[func] = decltype(this->cache)::mapped_type();
	}
	vector<FunctionCacheItem> &items = this->cache[func];
	bool found = false;
	for (size_t i = 0; i < items.size(); ++i)
	{
		if (items[i].match(d, FunctionTypeQuery(type->getParameterTypes(), type->isConst())))
		{
			items[i].setFunctionType(type);
			items[i].setCancelException(ex);
			found = true;
			break;
		}
	}
	if (!found)
	{
		items.push_back(FunctionCacheItem(type,ex));
	}
}

void FunctionCache::cacheFunctionType(const WorkScript::DebugInfo &d,
                                      Function *func,
                                      WorkScript::FunctionType *type) noexcept
{
	if (this->cache.find(func) == this->cache.end())
	{
		this->cache[func] = decltype(this->cache)::mapped_type();
	}
	vector<FunctionCacheItem> &items = this->cache[func];
	bool found = false;
	for (size_t i = 0; i < items.size(); ++i)
	{
		if (items[i].match(d, FunctionTypeQuery(type->getParameterTypes(), type->isConst())))
		{
			items[i].setFunctionType(type);
			found = true;
			break;
		}
	}
	if (!found)
	{
		items.push_back(FunctionCacheItem(type));
	}
}

bool FunctionCache::getCachedFunctionType(const DebugInfo &d,
										  Function *func,
										  const FunctionTypeQuery &query,
										  FunctionType **outType) const
{
	const auto &it = this->cache.find(func);
	if (it == this->cache.end())
	{
		return false;
	}
	const vector<FunctionCacheItem> &caches = it->second;
	for (size_t i = 0; i < caches.size(); ++i)
	{
		auto &cur = caches[i];
		if (cur.match(d, query))
		{
			*outType = cur.getFunctionType();
			return true;
		}
	}
	return false;
}

bool FunctionCacheItem::match(const WorkScript::DebugInfo &d, const WorkScript::FunctionTypeQuery &query) const noexcept
{
	return this->functionType->match(d,query);
}