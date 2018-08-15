#pragma once
#include <memory>
#include <functional>
#include "TermExpression.h"
class ExecuteCppCodeExpression :
	public TermExpression
{
public:
	ExecuteCppCodeExpression(const std::function<const std::shared_ptr<TermExpression>(Context*)> &evaluateFunction);
	virtual ~ExecuteCppCodeExpression();

 virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual bool equals(const std::shared_ptr<TermExpression>& targetExpression) const;
	virtual const std::string toString() const override;
	virtual void compile(CompileContext *context) override;

protected:
	std::function<const std::shared_ptr<TermExpression>(Context*)> evaluateFunction;
};

