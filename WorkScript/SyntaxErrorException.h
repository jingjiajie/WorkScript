#pragma once
#include <string>
#include "WorkScriptException.h"
class SyntaxErrorException :
	public WorkScriptException
{
public:
	inline SyntaxErrorException(SyntaxErrorException &&tmp)
		:WorkScriptException(std::forward<SyntaxErrorException>(tmp))
	{
		this->line = tmp.line;
		this->column = tmp.column;
	}

	inline SyntaxErrorException(const size_t &line,const size_t &column,const wchar_t *const message)
		: WorkScriptException(message)
	{
		this->line = line;
		this->column = column;
	}
	virtual ~SyntaxErrorException();

	std::string toString() const;

protected:
	size_t line, column;

};

