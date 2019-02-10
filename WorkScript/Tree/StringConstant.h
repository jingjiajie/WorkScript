#pragma once
#include <string>
#include "Value.h"
#include "Program.h"
#include "Type.h"

namespace WorkScript {
	class StringConstant : public Value {
	public:
		StringConstant(const ExpressionInfo &info, const std::wstring &value)
			:Value(info), value(value) {}

		std::wstring getValue() const { return this->value; }
		Type * getType(InstantialContext *ctx) const override;
		GenerateResult generateIR(GenerateContext *context) override;
		std::wstring toString() const override;
		Value * clone() const override;
		ExpressionType getExpressionType() const override;
	protected:
		std::wstring value;
	};
}