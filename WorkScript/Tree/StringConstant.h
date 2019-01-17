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
		virtual Type * getType() const override;
		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual std::wstring toString() const override;
		virtual Constant * clone() const override;
	protected:
		std::wstring value;
	};
}