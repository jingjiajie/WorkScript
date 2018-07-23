#pragma once
#include <exception>
#include <string>

class WorkScriptException : public std::exception
{
public:
	WorkScriptException(std::string message);
	virtual ~WorkScriptException();
};

