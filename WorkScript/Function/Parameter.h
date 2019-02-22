#pragma once
#include <string>
#include "Expression.h"
#include "Type.h"

namespace WorkScript 
{
	class Value;

	class Parameter
	{
	public:
		inline Parameter() noexcept = default;

		inline Parameter(const std::wstring &name, Type *type = nullptr) noexcept{
			this->setName(name);
			this->setType(type);
		}

		~Parameter() noexcept;

		inline const std::wstring & getName()const noexcept{ return this->name; }
		inline void setName(const std::wstring &name) noexcept{ this->name = name; }
		inline Value * getDefaultValue() const noexcept{ return this->defaultValue; }
		void setDefaultValue(Value *value) noexcept;

		Type * getType(InstantialContext *ctx = nullptr);
		inline void setType(Type *type) { this->type = type; }
	private:
		std::wstring name;
		Type *type = nullptr;
		Value *defaultValue = nullptr;
	};
}