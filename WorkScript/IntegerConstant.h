#pragma once
#include "Constant.h"

namespace WorkScript {
	class IntegerConstant : public Constant {
	public:
		IntegerConstant(Type *type, long long value)
			:type(type), value(value) {}

		long long getValue() const { return this->value; }
		virtual Type * getType() override;
		virtual GenerateResult generateLLVMIR(GenerateContext *context) override;
		virtual std::wstring toString() const override;
		virtual Constant * clone() const override;
	protected:
		long long value;
		Type *type = nullptr;
	};
}