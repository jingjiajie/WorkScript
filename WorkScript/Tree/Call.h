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

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual Type * getType(InstantializeContext *context) const override;
		virtual std::wstring toString() const override;
		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const override;

		std::wstring toFunctionDeclString(InstantializeContext *context) const;

		inline decltype(auto) getParameters() const
		{
			return this->parameters;
		}
	protected:
		std::wstring functionName;
		MultiValue *parameters = nullptr;
	};
}