#pragma once
#include "UnaryOperatorExpression.h"

namespace WorkScript {
	class NegativeExpression :
		public UnaryOperatorExpression
	{
	public:
		inline NegativeExpression(Expression *subExpression)
			:UnaryOperatorExpression(subExpression)
		{

		}

		inline NegativeExpression()
			: UnaryOperatorExpression()
		{

		}

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};

}