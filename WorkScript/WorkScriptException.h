#pragma once
#include <exception>
#include <string>
#include "Location.h"

#define EXCEPTION_COMMON_DECL(CLASS_NAME) \
class CLASS_NAME : public WorkScriptException { public: using WorkScriptException::WorkScriptException; };

namespace WorkScript {
	class WorkScriptException : public std::exception
	{
	public:
		inline WorkScriptException(Location loc, const std::wstring &wmsg)
			:location(loc)
		{
			this->setMessage(wmsg.c_str());
		}

		virtual const char * what() const override;

		void setMessage(const std::wstring &msg);
	protected:
		Location location;
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
	EXCEPTION_COMMON_DECL(TypeNotFoundException);
	EXCEPTION_COMMON_DECL(TypeMismatchedException);
	EXCEPTION_COMMON_DECL(InternalException);
}




