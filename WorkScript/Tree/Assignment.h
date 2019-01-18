#pragma once
#include "BinaryOperator.h"

namespace WorkScript {

	class Assignment :
		public BinaryOperator
	{
	public:
		Assignment(const ExpressionInfo &exprInfo,Expression *leftExpression, Expression *rightExpression);

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
		virtual Type * getType(InstantializeContext *context) const override;

	protected:
		virtual std::wstring getOperatorString() const override;
		Type * makeSymbolOfRightType(const std::wstring &name, InstantializeContext *ctx) const;
	};

}