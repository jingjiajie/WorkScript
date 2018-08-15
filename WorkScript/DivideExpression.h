#pragma once
#include "BinaryTermExpression.h"
#include "NumberExpression.h"

class DivideExpression :
	public BinaryTermExpression
{
public:
	DivideExpression();
	DivideExpression(const std::shared_ptr<TermExpression> &, const std::shared_ptr<TermExpression> &);
	virtual ~DivideExpression();

    virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual const std::string toString() const override;

private:
	std::shared_ptr<NumberExpression> numberDivideNumber(const std::shared_ptr<NumberExpression>&, const std::shared_ptr<NumberExpression>&) const;
};

