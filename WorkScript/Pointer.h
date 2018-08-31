#pragma once
#include "EnablePointer.h"

template<typename T>
class Pointer
{
public:
	inline Pointer(EnablePointer *const ptr)
	{
		ptr->increaseReference();
		this->ptr = ptr;
	}

	inline Pointer(const Pointer &p)
	{
		this->ptr = p.ptr;
		this->ptr->increaseReference();
	}

	inline ~Pointer()
	{
		this->ptr->decreaseReference();
		if (this->ptr->getReferences() == 0)
		{
			this->ptr->release();
		}
	}

	inline T *const get()
	{
		return (T*)this->ptr;
	}

	inline T *const operator->()
	{
		return (T*)this->ptr;
	}
private:
	 EnablePointer *ptr = nullptr;
};
