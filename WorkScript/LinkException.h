#pragma once
#include "WorkScriptException.h"
class LinkException :
	public WorkScriptException
{
public:
	inline LinkException(LinkException &&tmp)
		:WorkScriptException(std::forward<LinkException>(tmp))
	{

	}

	inline LinkException(const wchar_t *const message)
		: WorkScriptException(this->makeErrorMessage(message).c_str())
	{
		
	}

private:
	inline std::wstring makeErrorMessage(const wchar_t *msg)const {
		std::wstringstream ss;
		ss << L"Á´½Ó´íÎó£º" << msg;
		return ss.str();
	}
};