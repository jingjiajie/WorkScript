#pragma once
#include "Expression.h"
#include "Type.h"

namespace WorkScript {
	class IntegerExpression;
	class FloatExpression;
	class StringExpression;

	class BinaryOperatorExpression :
		public Expression
	{
	public:
		inline BinaryOperatorExpression(Program *p) : Expression(p)
		{
		}

		inline BinaryOperatorExpression(Program *p, Expression *left, Expression *right) : Expression(p)
		{
			this->setLeftExpression(left);
			this->setRightExpression(right);
		}

		virtual ~BinaryOperatorExpression();

		virtual std::wstring toString() const override;

		inline Expression * getLeftExpression() const
		{
			return this->leftExpression;
		}

		inline void setLeftExpression(Expression *left)
		{
			this->leftExpression = left;
		}

		inline Expression * getRightExpression() const
		{
			return this->rightExpression;
		}

		inline void setRightExpression(Expression *right)
		{
			this->rightExpression = right;
		}
	protected:
		Expression *leftExpression;
		Expression *rightExpression;

		virtual std::wstring getOperatorString() const = 0;
	};

}