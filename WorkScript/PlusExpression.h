#pragma once
#include "BinaryCalculateExpression.h"
namespace WorkScript {

	class DoubleExpression;
	class StringExpression;

	class PlusExpression :
		public BinaryCalculateExpression
	{
	public:
		inline PlusExpression(Expression *left, Expression *right)
			:BinaryCalculateExpression(left, right)
		{

		}
		inline PlusExpression()
			: BinaryCalculateExpression()
		{

		}
		virtual ~PlusExpression();

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};

}