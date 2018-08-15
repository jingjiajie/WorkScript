#pragma once
#include "BinaryTermExpression.h"

class StringExpression;
class NumberExpression;

class MinusExpression :
	public BinaryTermExpression
{
public:
	MinusExpression();
	MinusExpression(const std::shared_ptr<TermExpression> &, const std::shared_ptr<TermExpression> &);
	virtual ~MinusExpression();

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual const std::string toString() const override;

private:
	std::shared_ptr<NumberExpression> numberMinusNumber(const std::shared_ptr<NumberExpression>&, const std::shared_ptr<NumberExpression>&) const;
	std::shared_ptr<StringExpression> stringMinusNumber(const std::shared_ptr<StringExpression>&, const std::shared_ptr<NumberExpression>&) const;
	//std::shared_ptr<StringExpression> stringMinusString(const std::shared_ptr<StringExpression>&, const std::shared_ptr<StringExpression>&) const;
};

