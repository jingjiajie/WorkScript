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
	    inline Exception() noexcept = default;

		inline explicit Exception(const std::wstring &wmsg) noexcept
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
		explicit inline CancelException(CancelScope scope) noexcept
			:cancelScope(scope) {}

		inline CancelException(const CancelException &e) noexcept
			:Exception(), cancelScope(e.cancelScope)
		{ }

		inline void rethrowAbove(CancelScope scope) const{
			if(this->cancelScope > scope) throw *this;
		}

		inline CancelScope getCancelScope() const noexcept{
			return this->cancelScope;
		}
	private:
		CancelScope cancelScope;
	};

	WS_EXCEPTION_COMMON_DECL(InternalException)
}
