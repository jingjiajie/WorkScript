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
		inline UnaryOperatorExpression(EXPRESSION_CTOR_FORMAL_PARAMS, Expression *sub, OperatorType t)
			:EXPRESSION_CTOR_CALL, operatorType(t), subExpression(sub){ }

		virtual ~UnaryOperatorExpression();

		virtual void bindSymbols() override;
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