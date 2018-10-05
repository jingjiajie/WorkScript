#pragma once
#include "BinaryCalculateExpression.h"
namespace WorkScript {
	class StringExpression;
	class DoubleExpression;
	class NumberExpression;

	class MinusExpression :
		public BinaryCalculateExpression
	{
	public:
		inline MinusExpression(Expression *left, Expression *right)
			:BinaryCalculateExpression(left, right)
		{

		}
		virtual ~MinusExpression();

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};

}