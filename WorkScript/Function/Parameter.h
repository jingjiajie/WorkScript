#pragma once
#include <string>
#include "Expression.h"
#include "Type.h"

namespace WorkScript 
{
	class Constant;

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
		inline Constant * getDefaultValue() { return this->defaultValue; }

		void setDefaultValue(Constant *value);

		inline bool isVarargs()const { return this->varargs; }
		inline void setVarargs(bool isVarargs) { this->varargs = isVarargs; }
		Type * getType(InstantializeContext *ctx = nullptr);
		inline void setType(Type *type) { this->type = type; }
		inline bool isDeclaredType() const{ return this->declaredType; }
		inline void setDeclaredType(bool isDeclaredType) { this->declaredType = isDeclaredType; }
	private:
		std::wstring name;
		Type *type = nullptr;
		Constant *defaultValue = nullptr;
		bool varargs = false;
		bool declaredType = false;
	};
}