#pragma once
#include "NumberExpression.h"
#include "StringExpression.h"
#include "BinaryTermExpression.h"
class MultiplyExpression :
	public BinaryTermExpression
{
public:
	MultiplyExpression();
	MultiplyExpression(const std::shared_ptr<TermExpression> &, const std::shared_ptr<TermExpression> &);
	virtual ~MultiplyExpression();

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual const std::string toString() const override;

private:
	std::shared_ptr<NumberExpression> numberMultiplyNumber(const std::shared_ptr<NumberExpression>&, const std::shared_ptr<NumberExpression>&) const;
	std::shared_ptr<StringExpression> stringMultiplyNumber(const std::shared_ptr<StringExpression>&, const std::shared_ptr<NumberExpression>&) const;
};

