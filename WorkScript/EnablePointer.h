#pragma once

class EnablePointer
{
	template<typename T>
	friend class Pointer;
protected:
	virtual ~EnablePointer() = default;

	virtual void release()
	{
		delete this;
	}

private:
	inline void increaseReference()
	{
		++references;
	}

	inline void decreaseReference()
	{
		--references;
	}

	inline const int getReferences()
	{
		return this->references;
	}

	int references = 0;
};