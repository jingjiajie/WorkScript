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
		:WorkScriptException(L"����δʵ�֣�")
	{

	}

	inline UnimplementedException(const wchar_t *const message)
		:WorkScriptException(message)
	{

	}
};