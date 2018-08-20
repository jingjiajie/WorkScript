#pragma once
#include "WorkScriptException.h"
class UninvocableException :
	public WorkScriptException
{
public:
	inline UninvocableException(UninvocableException &&tmp)
		:WorkScriptException(std::forward<UninvocableException>(tmp))
	{

	}

	inline UninvocableException(const char *const message)
		:WorkScriptException(message)
	{

	}
	virtual ~UninvocableException();
};

