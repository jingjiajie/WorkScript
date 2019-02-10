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
		inline Parameter() {}

		inline Parameter(const std::wstring &name, Type *type, bool isDeclaredType = false) {
			this->setName(name);
			this->setType(type);
			this->setDeclaredType(isDeclaredType);
		}

		~Parameter();

		inline const std::wstring & getName()const { return this->name; }
		inline void setName(const std::wstring &name) { this->name = name; }
		inline Value * getDefaultValue() { return this->defaultValue; }

		void setDefaultValue(Value *value);

		inline bool isVarargs()const { return this->varargs; }
		inline void setVarargs(bool isVarargs) { this->varargs = isVarargs; }
		Type * getType(InstantialContext *ctx = nullptr);
		inline void setType(Type *type) { this->type = type; }
		inline bool isDeclaredType() const{ return this->declaredType; }
		inline void setDeclaredType(bool isDeclaredType) { this->declaredType = isDeclaredType; }
	private:
		std::wstring name;
		Type *type = nullptr;
		Value *defaultValue = nullptr;
		bool varargs = false;
		bool declaredType = false;
	};
}