#pragma once
#include "TypeClassification.h"
#include "GenerateResult.h"
#include "GenerateContext.h"
#include "DebugInfo.h"

namespace WorkScript {
	class Expression;
	class Program;

	enum class StorageType{
		DEFAULT, AUTO, STATIC, EXTERN
	};

	enum class LinkageType{
		DEFAULT, INTERNAL, EXTERNAL
	};

	class Type
	{
	public:
		Type(bool isConst, bool isVolatile)
			:_const(isConst), _volatile(isVolatile) { }

		virtual ~Type(){ }
		virtual std::wstring getName() const = 0;
		virtual std::wstring getIdentifierString() const = 0;
		virtual bool equals(const Type *type) const;

		static GenerateResult generateLLVMTypeConvert(const DebugInfo &d, GenerateContext *context, Expression *expr, Type *targetType);
		static GenerateResult generateLLVMTypeConvert(const DebugInfo &d, GenerateContext *context, Expression *left, Expression *right, Type *promotedType);
		static Type * getPromotedType(const DebugInfo &d, Type *type1, Type *type2);
		static bool convertableTo(const DebugInfo &d, Type *src, Type *target);
		bool convertableTo(const DebugInfo &d, Type *target);

		inline bool isConst() const { return this->_const; }
		inline bool isVolatile() const { return this->_volatile; }

		virtual TypeClassification getClassification() const = 0;
		virtual llvm::Type* getLLVMType(GenerateContext *context) const = 0;

	protected:
		bool _const = false;
		bool _volatile = false;
	};
}