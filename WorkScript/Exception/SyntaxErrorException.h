#pragma once
#include <string>
#include <sstream>
#include "WorkScriptException.h"
#include "DebugInfo.h"

namespace WorkScript {
	class SyntaxErrorException :
		public WorkScriptException
	{
	public:
		inline SyntaxErrorException(DebugInfo loc, const std::wstring &message)
			: WorkScriptException(loc, this->makeErrorMessage(loc, message).c_str())
		{
		}

	protected:
		inline std::wstring makeErrorMessage(const DebugInfo &d, const std::wstring &msg)const {
			std::wstringstream ss;
			ss << L"语法错误（第" << d.getLocation().getLine() << L"行, 第" << d.getLocation().getColumn() << L"列）：" << msg;
			return ss.str();
		}
	};

}