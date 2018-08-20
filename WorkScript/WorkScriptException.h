#pragma once
#include <exception>
#include <string.h>
#include <utility>

class WorkScriptException : public std::exception
{
public:
	inline WorkScriptException(WorkScriptException &&tmp)
	{
		this->message = tmp.message;
		tmp.message = nullptr;
	}

	inline WorkScriptException(const WorkScriptException &tmp)
	{
		this->setMessage(tmp.message);
	}

	inline WorkScriptException(const char *const &lpszMsg)
	{
		this->setMessage(lpszMsg);
	}

	virtual ~WorkScriptException();

	virtual const char * what() const override
	{
		return this->message;
	}

	inline void setMessage(const char *const &lpszMsg)
	{
		auto buff = new char[strlen(lpszMsg) + 1];
		strcpy(buff, lpszMsg);
		this->message = buff;
	}
protected:
	const char *message;
};

