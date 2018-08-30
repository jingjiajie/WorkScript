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
		:WorkScriptException(L"方法未实现！")
	{

	}

	inline UnimplementedException(const wchar_t *const message)
		:WorkScriptException(message)
	{

	}
};