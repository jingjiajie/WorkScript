#pragma once
#include <string>
#include <sstream>
#include "WorkScriptException.h"
#include "Location.h"

namespace WorkScript {
	class SyntaxErrorException :
		public WorkScriptException
	{
	public:
		inline SyntaxErrorException(Location loc, const std::wstring &message)
			: WorkScriptException(this->makeErrorMessage(loc, message).c_str()), location(loc)
		{
		}

	protected:
		Location location;

		inline std::wstring makeErrorMessage(Location loc, const std::wstring &msg)const {
			std::wstringstream ss;
			ss << L"�﷨���󣨵�" << loc.getLine() << L"��, ��" << loc.getColumn() << L"�У���" << msg;
			return ss.str();
		}
	};

}