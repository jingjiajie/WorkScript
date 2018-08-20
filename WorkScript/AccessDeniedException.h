#pragma once
#include "WorkScriptException.h"
class AccessDeniedException :
	public WorkScriptException
{
public:
	inline AccessDeniedException(AccessDeniedException &&tmp)
		:WorkScriptException(std::forward<AccessDeniedException>(tmp))
	{

	}

	inline AccessDeniedException(const char *const message)
		:WorkScriptException(message)
	{

	}
	virtual ~AccessDeniedException();
};

