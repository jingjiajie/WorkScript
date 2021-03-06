#pragma once
#include "BinaryOperator.h"
#include "IntegerType.h"
namespace WorkScript {
	class Variable;

	class BinaryCompare :
		public BinaryOperator
	{
	public:
		enum CompareType {
			EQUAL, GREATER_THAN, GREATER_THAN_EQUAL, LESS_THAN, LESS_THAN_EQUAL
		};
		inline BinaryCompare(const ExpressionInfo &exprInfo,Expression *leftExpression, Expression *rightExpression,CompareType t)
			:BinaryOperator(exprInfo,leftExpression,rightExpression),compareType(t) { }

		GenerateResult generateIR(GenerateContext *context) override;
		DeducedInfo deduce(InstantialContext *context) const override;
		Expression * clone() const override;
		ExpressionType getExpressionType() const override;

		//inline Variable * getLeftVariable() const
		//{
		//	if (this->leftExpression->getExpressionType() == ExpressionType::VARIABLE) {
		//		return (Variable*)this->leftExpression;
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