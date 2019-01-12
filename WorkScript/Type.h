#pragma once
#include "stdafx.h"
#include "TypeClassification.h"
#include "GenerateResult.h"
#include "GenerateContext.h"

namespace WorkScript {
	class Expression;
	class Program;
	class VoidType;
	class IntegerType;
	class FloatType;
	class PointerType;

	class Type
	{
	public:
		Type(bool isConst, bool isVolatile)
			:_const(isConst), _volatile(isVolatile) { }

		virtual std::wstring getName() const = 0;
		virtual std::wstring getIdentifierString() const = 0;
		virtual bool equals(const Type *type) const;

		static GenerateResult generateLLVMTypeConvert(GenerateContext *context, Expression *expr, Type *targetType);
		static GenerateResult generateLLVMTypeConvert(GenerateContext *context, Expression *left, Expression *right, Type *promotedType);
		static Type * getPromotedType(Type *type1, Type *type2);
		static bool convertableTo(Type *src, Type *target);
		bool convertableTo(Type *target);

		inline bool isConst() const { return this->_const; }
		inline bool isVolatile() const { return this->_volatile; }

		virtual inline TypeClassification getClassification() const = 0;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const = 0;

	protected:
		bool _const = false;
		bool _volatile = false;
	};
}