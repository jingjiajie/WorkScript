#pragma once
#include "WorkScriptException.h"
#include <utility>
class IllegalValueException :
	public WorkScriptException
{
public:
	inline IllegalValueException(IllegalValueException &&tmp)
		:WorkScriptException(std::forward<IllegalValueException>(tmp))
	{

	}

	inline IllegalValueException(const wchar_t *const message)
		: WorkScriptException(message)
	{

	}
	virtual ~IllegalValueException();
};

