#pragma once
#include <exception>
#include <string>

#include "Defines.h"

#define WORKSCRIPT_EXCEPTION_CONSTRUCTORS(className) \
	inline className(className &&tmp) :WorkScriptException(std::forward<className>(tmp)) {} \
	inline className(const wchar_t *const message) : WorkScriptException(message) {} 

class WorkScriptException : public std::exception
{
public:
	inline WorkScriptException(const std::wstring &wmsg)
	{
		this->setMessage(wmsg.c_str());
	}

	virtual const char * what() const override;

	void setMessage(const std::wstring &msg);
protected:
	std::wstring message;
	std::string messageANSI;
};

