#pragma once
#include "Expression.h"
#include "Type.h"

#define BINARY_OPERATOR_CTOR_FORMAL_PARAMS EXPRESSION_CTOR_FORMAL_PARAMS,Expression *leftExpression, Expression *rightExpression
#define BINARY_OPERATOR_MEMBERS EXPRESSION_MEMBERS,leftExpression,rightExpression
#define BINARY_OPERATOR_CTOR_CALL BinaryOperatorExpression(BINARY_OPERATOR_MEMBERS)

namespace WorkScript {
	class IntegerExpression;
	class FloatExpression;
	class StringExpression;

	class BinaryOperatorExpression :
		public Expression
	{
	public:
		inline BinaryOperatorExpression(BINARY_OPERATOR_CTOR_FORMAL_PARAMS)
			:EXPRESSION_CTOR_CALL, leftExpression(leftExpression), rightExpression(rightExpression)	{	}

		virtual ~BinaryOperatorExpression();

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