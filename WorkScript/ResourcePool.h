#pragma once

typedef size_t HEXPR;

struct Resource
{
	void *ptr = nullptr;
	int refs = 0;
};

class ResourcePool
{
public:
	ResourcePool();
	virtual ~ResourcePool() {
		for (size_t i = 0; i < count; i++) {
			if (pool[i].ptr) {
				delete pool[i].ptr;
			}
		}
	}
	
	void *get(size_t offset) const {
		return pool[offset].ptr;
	}

	void set(size_t offset, void *ptrValue) {
		pool[offset].ptr = ptrValue;
	}

	void free(size_t start, size_t count) {
		for (size_t i = 0; i < count; i++) {
			size_t pos = start + i;
			if (this->pool[pos].ptr) {
				delete this->pool[pos].ptr;
				this->pool[pos].ptr = nullptr;
			}
		}
	}

	size_t alloc(size_t count) {
		if (this->count + count >= 1024) {
			throw "ÄÚ´æÒç³ö";
		}
		size_t start = this->count;
		this->count += count;
		return start;
	}
private:
	Resource pool[1024];
	size_t count = 0;
};