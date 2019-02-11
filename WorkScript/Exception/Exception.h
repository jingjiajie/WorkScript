#pragma once
#include <exception>
#include <string>
#include "DebugInfo.h"

#define WS_EXCEPTION_COMMON_DECL(CLASS_NAME) \
class CLASS_NAME : public Exception { public: using Exception::Exception; };

namespace WorkScript
{
	class Exception : public std::exception
	{
	public:
	    inline Exception() = default;

		inline explicit Exception(const std::wstring &wmsg)
		{
			this->setMessage(wmsg);
		}

		const char *what() const noexcept override;
		void setMessage(const std::wstring &msg);
	protected:
		std::string messageANSI;
	};


	enum class CancelScope {
		EXPRESSION, BLOCK, FUNCTION_FRAGMENT, FUNCTION, COMPILATION
	};
		
	class CancelException : public Exception{
	public:
		inline CancelException(CancelScope scope)
			:cancelScope(scope) {}

	private:
		CancelScope cancelScope;
	};

	WS_EXCEPTION_COMMON_DECL(InternalException)
}
