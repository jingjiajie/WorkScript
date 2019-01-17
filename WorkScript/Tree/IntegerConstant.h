#pragma once
#include "Constant.h"

namespace WorkScript {
	class IntegerConstant : public Constant {
	public:
		IntegerConstant(const ExpressionInfo &info, Type *type, long long value)
			:Constant(info), value(value), type(type) {}

		long long getValue() const { return this->value; }
		virtual Type * getType() const override;
		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual std::wstring toString() const override;
		virtual Constant * clone() const override;
	protected:
		long long value;
		Type *type = nullptr;
	};
}