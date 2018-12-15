#pragma once
#include "Expression.h"
#include "StringExpression.h"
namespace WorkScript {
	class UnaryOperatorExpression :
		public Expression
	{
	public:
		enum OperatorType {
			NEGATIVE,NOT
		};

		inline UnaryOperatorExpression(Program *p,OperatorType t, Expression *subExpression)
			:Expression(p)
		{
			this->operatorType = t;
			this->setSubExpression(subExpression);
		}

		virtual ~UnaryOperatorExpression();

		virtual std::wstring toString() const override;
		virtual Type * getType() const override;
		virtual Expression * clone() const override;
		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual ExpressionType getExpressionType() const override;

		inline Expression * getSubExpression() const
		{
			return this->subExpression;
		}
		inline void setSubExpression(Expression *right)
		{
			this->subExpression = right;
		}
	protected:
		Expression *subExpression;
		OperatorType operatorType;

		virtual std::wstring getOperatorString() const;
	};

}