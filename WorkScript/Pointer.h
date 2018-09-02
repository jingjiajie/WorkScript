#pragma once
#include "EnablePointer.h"

template<typename T>
class Pointer
{
	template<typename T1>
	friend class Pointer;
public:
	inline Pointer(EnablePointer *const ptr = nullptr)
	{
		if (ptr) {
			ptr->increaseReference();
		}
		this->ptr = ptr;
	}

	inline Pointer(const Pointer &p)
	{
		this->ptr = p.ptr;
		if (this->ptr) {
			this->ptr->increaseReference();
		}
	}

	inline ~Pointer()
	{
		if (!this->ptr)return;
		this->ptr->decreaseReference();
		if (this->ptr->getReferences() == 0)this->releaseByStrategy();
	}

	inline void releaseByStrategy()
	{
		if (this->ptr->releaseStrategy == ReleaseStrategy::CALL_RELEASE) {
			this->ptr->release();
		}
		else if (this->ptr->releaseStrategy == ReleaseStrategy::DELETE) {
			delete this->ptr;
		}
	}

	inline T *const get() const
	{
		return (T*)this->ptr;
	}

	template<typename T1>
	inline Pointer<T> & operator=(const Pointer<T1> &target)
	{
		return this->assign(target);
	}

	//他妈的，要是不声明这一条，编译器还是会自动在上一条模板实例化之前自动生成operator=
	inline Pointer<T> & operator=(const Pointer<T> &target)
	{
		return this->assign(target);
	}

	template<typename T1>
	inline Pointer<T> & assign(const Pointer<T1> &target)
	{
		//如果自己赋值给自己，则什么都不做
		if (target.ptr == this->ptr) return *this;
		if (this->ptr != nullptr) {
			this->ptr->decreaseReference();
			if (this->ptr->references == 0)this->releaseByStrategy();
		}
		target.ptr->increaseReference();
		this->ptr = target.ptr;
		return *this;
	}

	inline T *const operator->() const
	{
		return (T*)this->ptr;
	}

	inline const bool operator==(const EnablePointer *target) const
	{
		return this->ptr == target;
	}

	inline const bool operator!=(const EnablePointer *target) const
	{
		return this->ptr != target;
	}

	inline operator bool() const
	{
		return this->ptr != nullptr;
	}

	template<typename TBase>
	inline operator Pointer<TBase>() const
	{
		return Pointer<TBase>(this->ptr);
	}
private:
	 EnablePointer *ptr = nullptr;
};
