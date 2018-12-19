#pragma once
#include "Expression.h"
#include "OverloadTemplate.h"
#include "Type.h"

namespace WorkScript {
	class FunctionExpression;
	class MultiValueExpression;
	class Overload;

	class TemplateCallExpression :
		public Expression
	{
	public:
		inline TemplateCallExpression(EXPRESSION_CTOR_FORMAL_PARAMS, const std::wstring &funcName,OverloadTemplate *overloadTemplate, MultiValueExpression *params)
			:EXPRESSION_CTOR_CALL, bindOverloadTemplate(overloadTemplate), parameters(params), functionName(funcName) { }

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
		OverloadTemplate * bindOverloadTemplate = nullptr;
		std::wstring functionName;
		MultiValueExpression *parameters = nullptr;
	};
}