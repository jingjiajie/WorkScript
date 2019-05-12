#pragma once
#include "Expression.h"
#include "Type.h"
#include "MultiValue.h"

namespace WorkScript {
	class Function;

	class Call :
		public Expression
	{
	public:
		inline Call(const ExpressionInfo &exprInfo, const std::wstring &funcName, MultiValue *params)
			:Expression(exprInfo), functionName(funcName), parameters(params){ }

		GenerateResult generateIR(GenerateContext *context) override;
		DeducedInfo deduce(InstantialContext *context) const override;
		std::wstring toString() const override;
		ExpressionType getExpressionType() const override;
		Expression * clone() const override;

		std::wstring toFunctionDeclString(InstantialContext *context) const;

		inline decltype(auto) getParameters() const
		{
			return this->parameters;
		}
	protected:
		std::wstring functionName;
		MultiValue *parameters = nullptr;
	};
}
