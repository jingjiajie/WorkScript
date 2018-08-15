#pragma once
#include "WorkScriptException.h"
class UninvocableException :
	public WorkScriptException
{
public:
	UninvocableException(std::string message);
	virtual ~UninvocableException();
};

