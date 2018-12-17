#pragma once
#include "BinaryOperatorExpression.h"
#include "IntegerType.h"
namespace WorkScript {
	class VariableExpression;

	class BinaryCompareExpression :
		public BinaryOperatorExpression
	{
	public:
		enum CompareType {
			EQUAL, GREATER_THAN, GREATER_THAN_EQUAL, LESS_THAN, LESS_THAN_EQUAL
		};
		inline BinaryCompareExpression(BINARY_OPERATOR_CTOR_FORMAL_PARAMS,CompareType t)
			:BINARY_OPERATOR_CTOR_CALL,compareType(t) { }

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual IntegerType * getType() const override;
		virtual Expression * clone() const override;
		virtual ExpressionType getExpressionType() const override;

		//inline VariableExpression * getLeftVariable() const
		//{
		//	if (this->leftExpression->getExpressionType() == ExpressionType::VARIABLE_EXPRESSION) {
		//		return (VariableExpression*)this->leftExpression;
		//	}
		//	else {
		//		return nullptr;
		//	}
		//}

	protected:
		virtual GenerateResult generateLLVMIRInteger(GenerateContext *context, llvm::Value *left, llvm::Value *right, IntegerType *promotedType) const;
		virtual GenerateResult generateLLVMIRFloat(GenerateContext *context, llvm::Value *left, llvm::Value *right, FloatType *promotedType) const;
		virtual std::wstring getOperatorString() const override;

		CompareType compareType;
	};

}