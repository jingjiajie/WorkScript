#pragma once
#include "WorkScriptException.h"
class UnimplementedException : public WorkScriptException
{
public:
	UnimplementedException();
};