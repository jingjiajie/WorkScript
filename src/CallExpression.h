#pragma once
#include "Expression.h"
#include "Type.h"

namespace WorkScript {
	class FunctionExpression;
	class MultiValueExpression;
	class Function;

	class CallExpression :
		public Expression
	{
	public:
		inline CallExpression(const ExpressionInfo &exprInfo, const std::wstring &funcName, MultiValueExpression *params)
			:Expression(exprInfo), functionName(funcName), parameters(params){ }

		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual Type * getType(InstantializeContext *context) const override;
		virtual std::wstring toString() const override;
		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const;

		inline decltype(auto) getParameters() const
		{
			return this->parameters;
		}
	protected:
		std::wstring functionName;
		MultiValueExpression *parameters = nullptr;
	};
}