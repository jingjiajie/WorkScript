#pragma once
#include "Expression.h"
#include "StringExpression.h"
#include "Type.h"

namespace WorkScript {
	class BinaryOperatorExpression :
		public Expression
	{
	public:
		inline BinaryOperatorExpression()
		{
		}

		inline BinaryOperatorExpression(Expression *left, Expression *right)
		{
			this->setLeftExpression(left);
			this->setRightExpression(right);
		}

		virtual ~BinaryOperatorExpression();

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual std::wstring toString() const override;
		virtual Type * getType() const override;

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
		virtual std::wstring getOperatorFunctionName() const = 0;
	};

}