#pragma once
#include "Constant.h"

namespace WorkScript {
	class FloatConstant : public Constant {
	public:
		FloatConstant(const ExpressionInfo &info, Type *type, long double value)
			:Constant(info), value(value),type(type) {}

		long double getValue() const { return this->value; }
		virtual Type * getType() const override;
		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual std::wstring toString() const override;
		virtual Constant * clone() const override;

	protected:
		long double value;
		Type *type = nullptr;
	};
}