#pragma once
#include "Expression.h"
namespace WorkScript {
	class UnaryOperator :
		public Expression
	{
	public:
		enum OperatorType {
			NEGATIVE,NOT
		};
		inline UnaryOperator(const ExpressionInfo &exprInfo, Expression *sub, OperatorType t)
			:Expression(exprInfo), subExpression(sub), operatorType(t){ }

		virtual ~UnaryOperator();

		virtual std::wstring toString() const override;
		virtual Type * getType(InstantialContext *context) const override;
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