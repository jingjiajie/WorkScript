#pragma once
#include <memory>
#include "BinaryTermExpression.h"
#include "TypeExpression.h"
#include "BooleanExpression.h"
#include "NumberExpression.h"

class GreaterThanExpression :
	public BinaryTermExpression
{
public:
	GreaterThanExpression(const std::shared_ptr<TermExpression> &, const std::shared_ptr<TermExpression> &);
	virtual ~GreaterThanExpression();

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual const std::string toString() const override;

protected:
	const std::shared_ptr<BooleanExpression> numberGreaterThanNumber(const std::shared_ptr<NumberExpression>&, const std::shared_ptr<NumberExpression>&)const;
};