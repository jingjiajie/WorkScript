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
		inline CallExpression(Program *p, Overload *o, MultiValueExpression *params)
			:Expression(p), overload(o), parameters(params) { }

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
		Overload * overload;
		MultiValueExpression *parameters = nullptr;
	};
}