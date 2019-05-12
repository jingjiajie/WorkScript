#pragma once
#include <string>
#include "Expression.h"
#include "Type.h"

namespace WorkScript 
{
	class Value;

	class ParameterDecl
	{
	public:
		inline ParameterDecl() noexcept = default;

		inline ParameterDecl(const std::wstring &name, Type *type = nullptr, Expression *defaultValue = nullptr) noexcept
			: name(name), type(type), defaultValue(defaultValue)
		{ }

		~ParameterDecl() noexcept;

		inline const std::wstring & getName()const noexcept{ return this->name; }
		inline void setName(const std::wstring &name) noexcept{ this->name = name; }
		inline Expression * getDefaultValue() const noexcept{ return this->defaultValue; }
		void setDefaultValue(Expression *value) noexcept;

		Type * getType();
		inline void setType(Type *type) { this->type = type; }
	private:
		std::wstring name;
		Type *type = nullptr;
		Expression *defaultValue = nullptr;
	};
}