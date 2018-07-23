#pragma once
#include "WorkScriptException.h"
class AccessDeniedException :
	public WorkScriptException
{
public:
	AccessDeniedException();
	virtual ~AccessDeniedException();
};

