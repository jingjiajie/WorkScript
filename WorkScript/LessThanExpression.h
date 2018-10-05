#pragma once
#include "BinaryCompareExpression.h"

namespace WorkScript {
	class LessThanExpression :
		public BinaryCompareExpression
	{
	public:
		inline LessThanExpression(Expression *left, Expression *right)
			:BinaryCompareExpression(left, right)
		{

		}
		virtual ~LessThanExpression();

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};

}