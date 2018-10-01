#pragma once
#include <exception>
#include <string.h>
#include <utility>

#include "Defines.h"

#define WORKSCRIPT_EXCEPTION_CONSTRUCTORS(className) \
	inline className(className &&tmp) :WorkScriptException(std::forward<className>(tmp)) {} \
	inline className(const wchar_t *const message) : WorkScriptException(message) {} 

class WorkScriptException : public std::exception
{
public:
	inline WorkScriptException(WorkScriptException &&tmp)
	{
		this->message = tmp.message;
		tmp.message = nullptr;
	}

	inline WorkScriptException(const WorkScriptException &tmp) = delete;

	inline WorkScriptException(const wchar_t *const &lpszMsg)
	{
		this->setMessage(lpszMsg);
	}

	virtual ~WorkScriptException();

	virtual const char * what() const override
	{
		return this->message;
	}

	void setMessage(const wchar_t *const &lpszMsg);
protected:
	const char *message;
};

