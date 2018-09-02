#pragma once

enum class ReleaseStrategy : unsigned char{
	CALL_RELEASE,
	DELETE
};

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

	inline const ReleaseStrategy getReleaseStrategy()const
	{
		return this->releaseStrategy;
	}

	inline void setReleaseStrategy(const ReleaseStrategy strategy)
	{
		this->releaseStrategy = strategy;
	}

	ReleaseStrategy releaseStrategy = ReleaseStrategy::CALL_RELEASE;
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