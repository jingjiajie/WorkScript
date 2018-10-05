#pragma once
#include "BinaryCompareExpression.h"

namespace WorkScript {

	class GreaterThanEqualExpression :
		public BinaryCompareExpression
	{
	public:
		inline GreaterThanEqualExpression(Expression *left, Expression *right)
			:BinaryCompareExpression(left, right)
		{

		}
		virtual ~GreaterThanEqualExpression();

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};

}