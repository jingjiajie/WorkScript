#pragma once
#include "DoubleExpression.h"
#include "StringExpression.h"
#include "BinaryCalculateExpression.h"
namespace WorkScript {
	class MultiplyExpression :
		public BinaryCalculateExpression
	{
	public:
		inline MultiplyExpression(Expression *left, Expression *right)
			:BinaryCalculateExpression(left, right)
		{

		}
		MultiplyExpression()
			:BinaryCalculateExpression()
		{

		}
		virtual ~MultiplyExpression();

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};

}