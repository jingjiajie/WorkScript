#pragma once
#include "Value.h"

namespace WorkScript {
	class IntegerConstant : public Value {
	public:
		IntegerConstant(const ExpressionInfo &info, Type *type, long long value)
			:Value(info), value(value), type(type) {}

		long long getValue() const { return this->value; }
		Type * getType(InstantialContext *ctx) const override;
		GenerateResult generateIR(GenerateContext *context) override;
		std::wstring toString() const override;
		Value * clone() const override;
		ExpressionType getExpressionType() const override;
	protected:
		long long value;
		Type *type = nullptr;
	};
}