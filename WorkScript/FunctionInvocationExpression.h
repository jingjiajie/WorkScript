#pragma once
#include "Expression.h"
#include "TypeExpression.h"

class ListExpression;

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

	Expression* const getLeftExpression() const;
	void setLeftExpression(Expression* const &left);
	ListExpression* const getParameters() const;
	void setParameters(ListExpression* const& parameters);

protected:
	Expression * leftExpression = nullptr;
	ListExpression * parameters = nullptr;
};

