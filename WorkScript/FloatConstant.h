#pragma once
#include "Constant.h"

namespace WorkScript {
	class FloatConstant : public Constant {
	public:
		FloatConstant(Type *type, long double value)
			:type(type), value(value) {}

		long double getValue() const { return this->value; }
		virtual Type * getType() override;
		virtual GenerateResult generateLLVMIR(GenerateContext *context) override;
		virtual std::wstring toString() const override;
		virtual Constant * clone() const override;
	protected:
		long double value;
		Type *type = nullptr;
	};
}