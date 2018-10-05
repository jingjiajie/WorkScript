#pragma once
#include "BinaryOperatorExpression.h"

namespace WorkScript {

	class AssignmentExpression :
		public BinaryOperatorExpression
	{
	public:
		inline AssignmentExpression()
			:BinaryOperatorExpression()
		{
		}

		inline AssignmentExpression(Expression *left, Expression *right)
			: BinaryOperatorExpression(left, right)
		{
		}

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};

}