#pragma once
#include <memory>
#include "BinaryTermExpression.h"

class NumberExpression;
class StringExpression;

class PlusExpression :
	public BinaryTermExpression
{
public:
	PlusExpression();
	PlusExpression(const std::shared_ptr<TermExpression> &, const std::shared_ptr<TermExpression> &);
	virtual ~PlusExpression();

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual const std::string toString() const override;

private:
	std::shared_ptr<NumberExpression> numberPlusNumber(const std::shared_ptr<NumberExpression>&,const std::shared_ptr<NumberExpression>&) const;
	std::shared_ptr<StringExpression> exprPlusExpr(const std::shared_ptr<Expression>&, const std::shared_ptr<Expression>&) const;
};

