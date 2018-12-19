#pragma once
#include "BinaryOperatorExpression.h"

namespace WorkScript {

	class AssignmentExpression :
		public BinaryOperatorExpression
	{
	public:
		AssignmentExpression(BINARY_OPERATOR_CTOR_FORMAL_PARAMS);

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual Expression * instantialize(InstantializeContext *context) override;
		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;
		virtual Type * getType() const override;

	protected:
		virtual std::wstring getOperatorString() const override;
	};

}