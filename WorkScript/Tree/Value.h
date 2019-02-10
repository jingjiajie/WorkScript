#pragma once
#include "GenerateResult.h"
#include "GenerateContext.h"
#include "Expression.h"

namespace WorkScript {
    class Type;
    class InstantialContext;

	class Value : public Expression
	{
	public:
		explicit inline Value(const ExpressionInfo &exprInfo) noexcept
				: Expression(exprInfo)
		{}
		std::wstring toString() const override = 0;
		Value *clone() const override = 0;
		GenerateResult generateIR(GenerateContext *context) override = 0;
	};
}
