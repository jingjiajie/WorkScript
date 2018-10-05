#pragma once
#include "Expression.h"
#include "Type.h"

class FunctionExpression;
class ParameterExpression;
class Overload;

namespace WorkScript {
	class FunctionInvocationExpression :
		public Expression
	{
	public:
		inline FunctionInvocationExpression()
		{

		}
		virtual ~FunctionInvocationExpression();

		//virtual bool equals(Expression *) const override;
		virtual Type * getType() const override;
		virtual std::wstring toString() const override;
		virtual ExpressionType getExpressionType() const override;

		inline decltype(auto) getParameters() const
		{
			return this->parameters;
		}

		inline void setParameters(ParameterExpression *parameters)
		{
			this->parameters = parameters;
		}

	protected:
		std::wstring funcName;
		ParameterExpression *parameters = nullptr;
	};
}