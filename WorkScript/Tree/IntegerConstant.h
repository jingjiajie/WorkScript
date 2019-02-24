#pragma once
#include "Constant.h"

namespace WorkScript {
	class IntegerConstant : public Constant {
	public:
		IntegerConstant(const ExpressionInfo &info, Type *type, long long value)
			:Constant(info), value(value), type(type) {}

		long long getValue() const { return this->value; }
		Type * getType() const noexcept override;
		GenerateResult generateIR(GenerateContext *context) override;
		std::wstring toString() const override;
		Value * clone() const override;
		ExpressionType getExpressionType() const override;
	protected:
		long long value;
		Type *type = nullptr;
	};
}