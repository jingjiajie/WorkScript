#pragma once
#include "BinaryOperatorExpression.h"
namespace WorkScript {
	class VariableExpression;

	class BinaryCompareExpression :
		public BinaryOperatorExpression
	{
	public:
		inline BinaryCompareExpression(Expression *left, Expression *right)
			:BinaryOperatorExpression(left, right)
		{

		}

		inline BinaryCompareExpression()
			: BinaryOperatorExpression()
		{

		}
		virtual ~BinaryCompareExpression();
		virtual Type * getType() const override;

		inline VariableExpression * getLeftVariable() const
		{
			if (this->leftExpression->getExpressionType() == ExpressionType::VARIABLE_EXPRESSION) {
				return (VariableExpression*)this->leftExpression;
			}
			else {
				return nullptr;
			}
		}

	};

}