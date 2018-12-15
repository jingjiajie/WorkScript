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

		virtual bool equals(const Type *type) const;

		static GenerateResult generateLLVMTypePromote(GenerateContext *context, Expression *expr, Type *targetType);
		static GenerateResult generateLLVMTypePromote(GenerateContext *context, Expression *left, Expression *right, Type *promotedType);
		static Type * getPromotedType(Type *type1, Type *type2);

		virtual inline TypeClassification getClassification() const = 0;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const = 0;

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
		Program *program;
	};
}