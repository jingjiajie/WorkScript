#pragma once
#include <memory>
#include "Type.h"
#include "BooleanExpression.h"
#include "DoubleExpression.h"
#include "BinaryCompareExpression.h"

namespace WorkScript {

	class GreaterThanExpression :
		public BinaryCompareExpression
	{
	public:
		inline GreaterThanExpression(Expression *left, Expression *right)
			:BinaryCompareExpression(left, right)
		{
		}
		virtual ~GreaterThanExpression();

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};

}