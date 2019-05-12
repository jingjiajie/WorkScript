#pragma once
#include <string>
#include "Constant.h"
#include "Program.h"
#include "Type.h"

namespace WorkScript {
	class StringConstant : public Constant {
	public:
		StringConstant(const ExpressionInfo &info, const std::wstring &value)
			:Constant(info), value(value) {}

		std::wstring getValue() const { return this->value; }
		DeducedInfo deduce(InstantialContext *context) const override;
		GenerateResult generateIR(GenerateContext *context) override;
		std::wstring toString() const override;
		Value * clone() const override;
		ExpressionType getExpressionType() const override;
	protected:
		std::wstring value;
	};
}