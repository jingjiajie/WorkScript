#pragma once
#include "Expression.h"
#include "Type.h"

namespace WorkScript {
	class FunctionExpression;
	class ParameterExpression;
	class Overload;

	class FunctionInvocationExpression :
		public Expression
	{
	public:
		inline FunctionInvocationExpression()
		{

		}
		virtual ~FunctionInvocationExpression();

		//virtual bool equals(Expression *) const override;
		virtual GenerateResult generateIR(GenerateContext *context) override;
		virtual Type * getType() const override;
		virtual std::wstring toString() const override;
		virtual ExpressionType getExpressionType() const override;
		virtual Expression * clone() const;

		std::vector<Type*> getParameterTypes() const;

		inline decltype(auto) getParameters() const
		{
			return this->parameters;
		}

		inline void setParameters(ParameterExpression *parameters)
		{
			this->parameters = parameters;
		}

		inline void setFunctionName(const std::wstring &name)
		{
			this->funcName = name;
		}
	protected:
		std::wstring funcName;
		ParameterExpression *parameters = nullptr;
	};
}