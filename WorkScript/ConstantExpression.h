#pragma once
#include <string>
#include "Expression.h"
#include "Type.h"

namespace WorkScript {

	class ConstantExpression :
		public Expression
	{
	public:
		inline ConstantExpression(const ExpressionInfo &exprInfo, Constant * val)
			:Expression(exprInfo), value(val) { }

		virtual ~ConstantExpression();

		virtual std::wstring toString() const override;
		virtual Type * getType(InstantializeContext *context) const override;
		virtual GenerateResult generateIR(GenerateContext *context);
		virtual ExpressionType getExpressionType() const;
		virtual Expression * clone() const override;

		inline Constant * getValue() const { return this->value; }

	protected:
		Constant * value = nullptr;
	};
}