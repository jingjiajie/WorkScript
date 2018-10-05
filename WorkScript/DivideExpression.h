#pragma once
#include "BinaryCalculateExpression.h"
#include "DoubleExpression.h"

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
		virtual std::wstring getOperatorFunctionName() const override;
	};
}