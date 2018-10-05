#pragma once
#include "BinaryCompareExpression.h"

namespace WorkScript {
	class LessThanEqualExpression :
		public BinaryCompareExpression
	{
	public:
		inline LessThanEqualExpression(Expression *left, Expression *right)
			:BinaryCompareExpression(left, right)
		{

		}
		virtual ~LessThanEqualExpression();

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};

}