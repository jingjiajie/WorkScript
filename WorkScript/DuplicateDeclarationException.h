#pragma once
#include "WorkScriptException.h"
class DuplicateDeclarationException :
	public WorkScriptException
{
public:
	DuplicateDeclarationException(std::string message);
	virtual ~DuplicateDeclarationException();
};

