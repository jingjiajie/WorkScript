#pragma once
#include "WorkScriptException.h"
class DuplicateDeclarationException :
	public WorkScriptException
{
public:
	inline DuplicateDeclarationException(DuplicateDeclarationException &&tmp)
		:WorkScriptException(std::forward<DuplicateDeclarationException>(tmp))
	{

	}

	inline DuplicateDeclarationException(const wchar_t *const message)
		:WorkScriptException(message)
	{

	}
	virtual ~DuplicateDeclarationException();
};
