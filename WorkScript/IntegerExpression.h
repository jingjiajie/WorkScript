#pragma once
#include "Expression.h"

namespace WorkScript {
	class IntegerExpression :
		public Expression
	{
	public:
		inline IntegerExpression(int v) :value(v) {}

		virtual GenerateResult generateIR(GenerateContext *context);
		virtual ExpressionType getExpressionType() const override;
		virtual Type * getType() const override;
		virtual Expression * clone() const override;
		virtual std::wstring toString() const override;

		inline const int getValue() const {
			return this->value;
		}

		inline void setValue(const int &value) {
			this->value = value;
		}
	protected:
		int value;
	};
}

