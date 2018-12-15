#pragma once
#include "BinaryOperatorExpression.h"

namespace WorkScript {

	class AssignmentExpression :
		public BinaryOperatorExpression
	{
	public:
		inline AssignmentExpression(Program *p, Expression *left, Expression *right)
			: BinaryOperatorExpression(p, left, right){}

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
		virtual Type * getType() const override;

	protected:
		virtual std::wstring getOperatorString() const override;
	};

}