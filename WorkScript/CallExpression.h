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
		inline CallExpression(EXPRESSION_CTOR_FORMAL_PARAMS,const std::wstring &funcName, MultiValueExpression *params)
			:EXPRESSION_CTOR_CALL, parameters(params), functionName(funcName) { }

		virtual void bindSymbols() override;
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