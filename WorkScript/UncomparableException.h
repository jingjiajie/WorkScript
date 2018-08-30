#pragma once
#include "WorkScriptException.h"
class UncomparableException :
	public WorkScriptException
{
public:
	inline UncomparableException(UncomparableException &&tmp)
		:WorkScriptException(std::forward<UncomparableException>(tmp))
	{

	}

	inline UncomparableException(const wchar_t *const message)
		: WorkScriptException(message)
	{

	}

	virtual ~UncomparableException();
};

