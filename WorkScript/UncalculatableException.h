#pragma once
#include "WorkScriptException.h"
class UncalculatableException :
	public WorkScriptException
{
public:
	inline UncalculatableException(UncalculatableException &&tmp)
		:WorkScriptException(std::forward<UncalculatableException>(tmp))
	{

	}

	inline UncalculatableException(const wchar_t *const message)
		: WorkScriptException(message)
	{

	}

	virtual ~UncalculatableException();
};

