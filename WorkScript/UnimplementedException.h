#pragma once
#include "WorkScriptException.h"
class UnimplementedException : public WorkScriptException
{
public:
	inline UnimplementedException(UnimplementedException &&tmp)
		:WorkScriptException(std::forward<UnimplementedException>(tmp))
	{

	}

	inline UnimplementedException()
		:WorkScriptException("����δʵ�֣�")
	{

	}

	inline UnimplementedException(const char *const message)
		:WorkScriptException(message)
	{

	}
};