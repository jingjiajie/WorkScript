#pragma once
#include "Expression.h"
#include "StringExpression.h"
namespace WorkScript {
	class UnaryOperatorExpression :
		public Expression
	{
	public:
		inline UnaryOperatorExpression()
		{
		}

		inline UnaryOperatorExpression(Expression *subExpression)
		{
			this->setSubExpression(subExpression);
		}

		virtual ~UnaryOperatorExpression();

		//virtual bool equals(Expression *) const override;
		virtual std::wstring toString() const override;
		virtual Type * getType() const override;
		virtual GenerateResult generateIR(GenerateContext *context) override;

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

		virtual std::wstring getOperatorString() const = 0;
		virtual std::wstring getOperatorFunctionName() const = 0;
	};

}