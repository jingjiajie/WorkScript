#pragma once
#include <string>
#include "Constant.h"
#include "Program.h"
#include "Type.h"

namespace WorkScript {
	class StringConstant : public Constant {
	public:
		StringConstant(const std::wstring &value)
			: value(value) {}

		std::wstring getValue() const { return this->value; }
		virtual Type * getType() override;
		virtual GenerateResult generateLLVMIR(GenerateContext *context) override;
		virtual std::wstring toString() const override;
		virtual Constant * clone() const override;
	protected:
		std::wstring value;
	};
}