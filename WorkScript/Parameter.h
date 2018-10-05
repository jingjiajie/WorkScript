#pragma once
#include <string>
#include "Expression.h"
#include "Type.h"

namespace WorkScript 
{
	class Parameter
	{
	public:
		inline Parameter() {}

		inline Parameter(const std::wstring &name, Type *type) {
			this->setName(name);
			this->setType(type);
		}

		inline Parameter(const std::wstring &name, Type *type, Expression *defaultValue) {
			this->setName(name);
			this->setType(type);
			this->setDefaultValue(defaultValue);
		}

		inline const std::wstring & getName()const {
			return this->name;
		}

		inline void setName(const std::wstring &name) {
			this->name = name;
		}

		inline Expression * getDefaultValue()const {
			return this->defaultValue;
		}

		inline void setDefaultValue(Expression *value) {
			this->defaultValue = value;
		}

		inline bool isVarargs()const {
			return this->varargs;
		}

		inline void setVarargs(bool isVarargs) {
			this->varargs = isVarargs;
		}

		inline Type * getType() {
			return this->type;
		}

		inline void setType(Type *type) {
			this->type = type;
		}

	private:
		std::wstring name;
		Type *type;
		Expression * defaultValue = nullptr;
		bool varargs = false;
	};
}