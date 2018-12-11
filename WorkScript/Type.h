#pragma once
#include "stdafx.h"
#include "Expression.h"
#include "TypeClassification.h"

namespace WorkScript {
	class Program;
	class Type
	{
	public:
		inline Type(Program *program, const std::wstring &name)
		{
			this->setName(name);
			this->program = program;
		}

		inline bool equals(const Type *type) const
		{
			return type == this;
		}

		virtual inline TypeClassification getClassification() const = 0;
		virtual llvm::Type* getLLVMType() const = 0;

		//ÀàÃû
		inline const std::wstring & getName() const
		{
			return this->name;
		}

		inline void setName(const std::wstring &name)
		{
			this->name = name;
		}

	protected:
		std::wstring name;
		TypeClassification classification;
		Program *program;
	};
}