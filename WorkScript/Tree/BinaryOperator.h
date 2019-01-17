#pragma once
#include "Expression.h"
#include "Type.h"

namespace WorkScript {
	class IntegerExpression;
	class FloatExpression;
	class StringExpression;

	class BinaryOperator :
		public Expression
	{
	public:
		inline BinaryOperator(const ExpressionInfo &exprInfo,Expression *leftExpression, Expression *rightExpression)
			:Expression(exprInfo), leftExpression(leftExpression), rightExpression(rightExpression)	{	}

		virtual ~BinaryOperator();

		virtual std::wstring toString() const override;

		inline Expression * getLeftExpression() const { return this->leftExpression; }
		inline void setLeftExpression(Expression *left) { this->leftExpression = left; }
		inline Expression * getRightExpression() const { return this->rightExpression; }
		inline void setRightExpression(Expression *right) { this->rightExpression = right; }
	protected:
		Expression *leftExpression;
		Expression *rightExpression;

		virtual std::wstring getOperatorString() const = 0;
	};

}