#pragma once
#include "Value.h"

namespace WorkScript {
	class FloatConstant : public Value {
	public:
		FloatConstant(const ExpressionInfo &info, Type *type, long double value)
			:Value(info), value(value),type(type) {}

		long double getValue() const { return this->value; }
		Type * getType(InstantialContext *ctx) const override;
		GenerateResult generateIR(GenerateContext *context) override;
		std::wstring toString() const override;
		Value * clone() const override;
		ExpressionType getExpressionType() const override;
	protected:
		long double value;
		Type *type = nullptr;
	};
}