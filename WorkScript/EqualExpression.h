#pragma once
#include "BinaryTermExpression.h"
class EqualExpression :
	public BinaryTermExpression
{
public:
	EqualExpression();
	virtual ~EqualExpression();

	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual const std::string toString() const override;

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	virtual bool equals(const std::shared_ptr<TermExpression>&) const override;
};