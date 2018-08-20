#pragma once
#include "WorkScriptException.h"
class UnassignableExpection :
	public WorkScriptException
{
public:
	inline UnassignableExpection(UnassignableExpection &&tmp)
		:WorkScriptException(std::forward<UnassignableExpection>(tmp))
	{

	}

	inline UnassignableExpection(const char *const message)
		:WorkScriptException(message)
	{

	}
	virtual ~UnassignableExpection();
};

