#pragma once
#include "BinaryCalculateExpression.h"
namespace WorkScript {
	class ModulusExpression :
		public BinaryCalculateExpression
	{
	public:
		inline ModulusExpression(Expression *left, Expression *right)
			:BinaryCalculateExpression(left, right)
		{

		}

		inline ModulusExpression()
			: BinaryCalculateExpression()
		{

		}

		virtual ~ModulusExpression();

		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
	protected:
		virtual std::wstring getOperatorString() const override;
		virtual std::wstring getOperatorFunctionName() const override;
	};
}