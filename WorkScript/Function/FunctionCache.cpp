#include "FunctionCache.h"
#include "Function.h"

using namespace WorkScript;
using namespace std;

void FunctionCache::cacheFunctionType(const WorkScript::DebugInfo &d,
                                      Function *func,
                                      WorkScript::FunctionType *type) noexcept
{
	if (this->cache.find(func) == this->cache.end())
	{
		this->cache[func] = decltype(this->cache)::mapped_type();
	}
	vector<FunctionType*> &items = this->cache[func];
	bool found = false;
	for (size_t i = 0; i < items.size(); ++i)
	{
		if (items[i]->match(d, FunctionTypeQuery(type->getParameterTypes(), type->isConst())))
		{
			items[i] = type;
			found = true;
			break;
		}
	}
	if (!found)
	{
		items.push_back(type);
	}
}

bool FunctionCache::getCachedFunctionType(const DebugInfo &d,
										  Function *func,
										  const FunctionTypeQuery &query,
										  FunctionType **outType) const noexcept
{
	const auto &it = this->cache.find(func);
	if (it == this->cache.end())
	{
		return false;
	}
	const vector<FunctionType *> &caches = it->second;
	for (size_t i = 0; i < caches.size(); ++i)
	{
		FunctionType *cur = caches[i];
		if (cur->match(d, query))
		{
			*outType = cur;
			return true;
		}
	}
	return false;
}