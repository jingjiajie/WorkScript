#pragma once
#include "BinaryCalculateExpression.h"

namespace WorkScript {

	class DivideExpression :
		public BinaryCalculateExpression
	{
	public:
		inline DivideExpression()
			:BinaryCalculateExpression()
		{
		}

		inline DivideExpression(Expression *left, Expression *right)
			: BinaryCalculateExpression(left, right)
		{
		}

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;

		virtual GenerateResult generateLLVMIRIntegerInteger(GenerateContext *context, IntegerExpression *left, IntegerExpression *right) const override;
		virtual GenerateResult generateLLVMIRIntegerFloat(GenerateContext *context, IntegerExpression *left, FloatExpression *right) const override;
		virtual GenerateResult generateLLVMIRFloatInteger(GenerateContext *context, FloatExpression *left, IntegerExpression *right) const override;
		virtual GenerateResult generateLLVMIRFloatFloat(GenerateContext *context, FloatExpression *left, FloatExpression *right) const override;
	};
}