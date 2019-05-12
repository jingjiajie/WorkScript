#pragma once
#include "BinaryOperator.h"

namespace WorkScript {
	class BinaryCalculate :
		public BinaryOperator
	{
	public:
		enum CalculateType {
			PLUS,MINUS,MULTIPLY,DIVIDE,MODULUS
		};

		inline BinaryCalculate(const ExpressionInfo &exprInfo,Expression *leftExpression, Expression *rightExpression,CalculateType calcType)
			:BinaryOperator(exprInfo,leftExpression,rightExpression), calculateType(calcType)	{	}

		GenerateResult generateIR(GenerateContext *context) override;
		DeducedInfo deduce(InstantialContext *context) const override;
		Expression * clone() const override;
		ExpressionType getExpressionType() const override;

	protected:
		virtual GenerateResult generateLLVMIRInteger(GenerateContext *context, llvm::Value *left, llvm::Value *right, IntegerType *promotedType) const;
		virtual GenerateResult generateLLVMIRFloat(GenerateContext *context, llvm::Value *left, llvm::Value *right, FloatType *promotedType) const;
		virtual std::wstring getOperatorString() const override;

		CalculateType calculateType;
	};
}