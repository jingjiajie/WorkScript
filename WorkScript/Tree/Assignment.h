#pragma once
#include "BinaryOperator.h"

namespace WorkScript {

	class Assignment :
		public BinaryOperator
	{
	public:
		Assignment(const ExpressionInfo &exprInfo,Expression *leftExpression, Expression *rightExpression);

		GenerateResult generateIR(GenerateContext *context) override;
		ExpressionType getExpressionType() const override;
		Expression * clone() const override;
		DeducedInfo deduce(InstantialContext *context) const override;

	protected:
		std::wstring getOperatorString() const override;
		SymbolInfo * syncSymbol(const std::wstring &name, InstantialContext *ctx) const;
	};

}