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
		:WorkScriptException("方法未实现！")
	{

	}

	inline UnimplementedException(const char *const message)
		:WorkScriptException(message)
	{

	}
};