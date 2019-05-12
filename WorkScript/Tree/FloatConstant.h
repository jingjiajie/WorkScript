#pragma once
#include "Constant.h"

namespace WorkScript {
	class FloatConstant : public Constant {
	public:
		FloatConstant(const ExpressionInfo &info, Type *type, long double value)
			:Constant(info), value(value),type(type) {}

		long double getValue() const { return this->value; }
		DeducedInfo deduce(InstantialContext *context) const override;
		GenerateResult generateIR(GenerateContext *context) override;
		std::wstring toString() const override;
		Value * clone() const override;
		ExpressionType getExpressionType() const override;
	protected:
		long double value;
		Type *type = nullptr;
	};
}