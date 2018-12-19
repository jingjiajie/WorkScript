#pragma once
#include <exception>
#include <string>

#define EXCEPTION_COMMON_DECL(CLASS_NAME) \
class CLASS_NAME : public WorkScriptException { public: using WorkScriptException::WorkScriptException; };

namespace WorkScript {
	class WorkScriptException : public std::exception
	{
	public:
		inline WorkScriptException(const std::wstring &wmsg)
		{
			this->setMessage(wmsg.c_str());
		}

		virtual const char * what() const override;

		void setMessage(const std::wstring &msg);
	protected:
		std::wstring message;
		std::string messageANSI;
	};

	EXCEPTION_COMMON_DECL(AccessDeniedException);
	EXCEPTION_COMMON_DECL(DuplicateDeclarationException);
	EXCEPTION_COMMON_DECL(IllegalValueException);
	EXCEPTION_COMMON_DECL(UnassignableExpection);
	EXCEPTION_COMMON_DECL(UncalculatableException);
	EXCEPTION_COMMON_DECL(UncomparableException);
	EXCEPTION_COMMON_DECL(UnimplementedException);
	EXCEPTION_COMMON_DECL(UninvocableException);
	EXCEPTION_COMMON_DECL(UndefinedSymbolException);
}




