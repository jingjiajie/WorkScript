#pragma once
#include "Expression.h"
#include "TypeExpression.h"

class ParameterExpression;

class FunctionInvocationExpression :
	public Expression
{
public:
	inline FunctionInvocationExpression(const StorageLevel level = StorageLevel::TEMP)
	{
		this->setStorageLevel(level);
	}
	virtual ~FunctionInvocationExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	virtual bool equals(Context *const &context,Expression* const&) const override;

	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;
	virtual void compile(CompileContext *const& context) override;

	inline Expression* const getLeftExpression() const
	{
		return this->leftExpression;
	}

	inline void setLeftExpression(Expression* const &left)
	{
		this->leftExpression = left;
	}

	inline ParameterExpression* const getParameters() const
	{
		return this->parameters;
	}

	inline void setParameters(ParameterExpression* const& parameters)
	{
		this->parameters = parameters;
	}

protected:
	Expression * leftExpression = nullptr;
	ParameterExpression * parameters = nullptr;
};

