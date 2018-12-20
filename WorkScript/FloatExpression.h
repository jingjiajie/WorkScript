#pragma once
#include "Expression.h"
#include "FloatType.h"

namespace WorkScript {

	class FloatExpression :
		public Expression
	{
	public:
		inline FloatExpression(const ExpressionInfo &exprInfo, FloatType *type, double v);

		virtual ExpressionType getExpressionType() const;
		virtual Expression * instantialize(InstantializeContext *context);
		virtual GenerateResult generateIR(GenerateContext *context);
		virtual Type * getType() const override;
		virtual std::wstring toString() const override;
		virtual Expression * clone() const override;

		inline double getValue() const {
			return this->value;
		}

		inline void setValue(double value) {
			this->value = value;
		}
	protected:
		double value;
		FloatType *type;
	};

}