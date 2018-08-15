#pragma once
#include "TermExpression.h"
#include "TypeExpression.h"

class ListExpression;

class FunctionInvocationExpression :
	public TermExpression
{
public:
	FunctionInvocationExpression();
	virtual ~FunctionInvocationExpression();

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	virtual bool equals(const std::shared_ptr<TermExpression>&) const override;

	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual const std::string toString() const override;
	virtual void compile(CompileContext *context) override;

	const std::shared_ptr<TermExpression> getLeftExpression() const;
	void setLeftExpression(const std::shared_ptr<TermExpression> &left);
	const std::shared_ptr<ListExpression> getParameters() const;
	void setParameters(const std::shared_ptr<ListExpression>& parameters);

protected:
	std::shared_ptr<TermExpression> leftExpression;
	std::shared_ptr<ListExpression> parameters;
};

