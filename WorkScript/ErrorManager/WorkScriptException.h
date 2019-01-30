#pragma once
#include <exception>
#include <string>
#include "DebugInfo.h"

namespace WorkScript
{
	class WorkScriptException : public std::exception
	{
	public:
		inline WorkScriptException(const DebugInfo &d, const std::wstring &wmsg)
				: debugInfo(d)
		{
			std::wstring str = L"第" + std::to_wstring(d.getLocation().getLine()) + L"行，第" +
							   std::to_wstring(d.getLocation().getColumn()) + L"列：" + wmsg;
			this->setMessage(str);
		}

		const char *what() const noexcept override;

		void setMessage(const std::wstring &msg);

	protected:
		DebugInfo debugInfo;
		std::wstring message;
		std::string messageANSI;
	};
}



