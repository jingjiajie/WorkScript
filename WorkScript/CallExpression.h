#pragma once
#include "Expression.h"
#include "Type.h"

namespace WorkScript {
	class FunctionExpression;
	class MultiValueExpression;
	class Overload;

	class CallExpression :
		public Expression
	{
	public:
		inline CallExpression(const ExpressionInfo &exprInfo, const std::wstring &funcName, Overload *overload, MultiValueExpression *params)
			:Expression(exprInfo),bindOverload(overload), parameters(params), functionName(funcName) { }

		virtual Expression * instantialize(InstantializeContext *context) override;
		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual Type * getType() const override;
		virtual std::wstring toString() const override;
		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const;

		inline decltype(auto) getParameters() const
		{
			return this->parameters;
		}
	protected:
		Overload * bindOverload = nullptr;
		std::wstring functionName;
		MultiValueExpression *parameters = nullptr;
	};
}