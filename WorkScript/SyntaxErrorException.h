#pragma once
#include <string>
#include <sstream>
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
		: WorkScriptException(this->makeErrorMessage(line,column,message).c_str())
	{
		this->line = line;
		this->column = column;
	}

	virtual ~SyntaxErrorException();

protected:
	size_t line, column;

	inline std::wstring makeErrorMessage(const size_t &line, const size_t &column, const wchar_t *msg)const {
		std::wstringstream ss;
 		ss << L"语法错误（第" <<line << L"行, 第" << column << L"列）：" << msg;
		return ss.str();
	}
};

