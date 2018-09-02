#pragma once
template<typename TItem>
class ObjectPool
{
public:
	inline ObjectPool(size_t maxSize) 
	{
		this->buff = new TItem*[maxSize];
		this->count = 0;
		this->maxCount = maxSize;
	}

	inline ~ObjectPool() 
	{
		for (size_t i = 0; i < this->count; ++i)
		{
			delete this->buff[i];
		}
		delete[]this->buff;
	}

	inline TItem *const get()
	{
		if (this->count > 0)
		{
			return this->buff[--this->count];
		}
		else {
			return new TItem;
		}
	}

	inline void push(TItem *const &item)
	{
		if (this->count < this->maxCount) {
			this->buff[this->count++] = item;
		}
		else {
			delete item;
		}
	}
public:
	TItem ** buff;
	size_t count;
	size_t maxCount;
};

#define OBJECT_POOL_MEMBER_DECL(type) \
friend class ObjectPool<type>; \
thread_local static ObjectPool<type> _pool; \

#define OBJECT_POOL_MEMBER_IMPL(type,maxSize) \
thread_local ObjectPool<type> type::_pool(maxSize); \

#define OBJECT_POOL_GET \
_pool.get()

#define OBJECT_POOL_PUSH(lpObj) \
_pool.push(lpObj)