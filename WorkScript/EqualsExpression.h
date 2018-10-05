#pragma once
#include "BinaryCompareExpression.h"

namespace WorkScript {
	class EqualsExpression :
		public BinaryCompareExpression
	{
	public:
		inline EqualsExpression()
			:BinaryCompareExpression()
		{

		}

		inline EqualsExpression(Expression *left, Expression *right)
			: BinaryCompareExpression(left, right)
		{

		}

		virtual ~EqualsExpression();
		virtual Expression * clone() const override;
		virtual ExpressionType getExpressionType() const override;

	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};
}