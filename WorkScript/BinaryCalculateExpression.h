#pragma once
#include "BinaryOperatorExpression.h"

namespace WorkScript {
	class BinaryCalculateExpression :
		public BinaryOperatorExpression
	{
	public:
		enum CalculateType {
			PLUS,MINUS,MULTIPLY,DIVIDE,MODULUS
		};

		inline BinaryCalculateExpression(BINARY_OPERATOR_CTOR_FORMAL_PARAMS,CalculateType calcType)
			:BINARY_OPERATOR_CTOR_CALL, calculateType(calcType)	{	}

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual Type * getType() const override;
		virtual Expression * instantialize(InstantializeContext *context) override;
		virtual Expression * clone() const override;
		virtual ExpressionType getExpressionType() const override;

	protected:
		virtual GenerateResult generateLLVMIRInteger(GenerateContext *context, llvm::Value *left, llvm::Value *right, IntegerType *promotedType) const;
		virtual GenerateResult generateLLVMIRFloat(GenerateContext *context, llvm::Value *left, llvm::Value *right, FloatType *promotedType) const;
		virtual std::wstring getOperatorString() const override;

		CalculateType calculateType;
	};
}