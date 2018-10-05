#pragma once
#include "Expression.h"
#include "Type.h"

namespace WorkScript {

	class DoubleExpression :
		public Expression
	{
	public:
		inline DoubleExpression(double v) :value(v) {}

		virtual ExpressionType getExpressionType() const;
		virtual GenerateResult generateIR(GenerateContext *context);
		virtual Type * getType() const override;
		virtual std::wstring toString() const override;
		virtual Expression * clone() const override;

		inline const double getValue() const {
			return this->value;
		}

		inline void setValue(const double &value) {
			this->value = value;
		}
	protected:
		double value;
	};

}