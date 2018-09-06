#pragma once
#include "Expression.h"
#include "TypeExpression.h"

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

	virtual const Pointer<Expression> evaluate(Context *const& context) override;
	virtual bool equals(Context *const &context,const Pointer<Expression> &) const override;
	const Pointer<FunctionExpression> getFunctionExpression(Context *const context) const;
	const Pointer<ParameterExpression> getEvaluatedParameters(Context *const context);
	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;
	virtual void compile(CompileContext *const& context) override;

	inline const Pointer<Expression> getLeftExpression() const
	{
		return this->leftExpression;
	}

	inline void setLeftExpression(const Pointer<Expression> &left)
	{
		this->leftExpression = left;
	}

	inline const Pointer<ParameterExpression> getParameters() const
	{
		return this->parameters;
	}

	inline void setParameters(const Pointer<ParameterExpression> & parameters)
	{
		this->parameters = parameters;
	}

protected:
	Pointer<Expression> leftExpression = nullptr;
	Pointer<ParameterExpression> parameters = nullptr;
};

