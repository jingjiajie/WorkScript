#pragma once
#include "TermExpression.h"
class NumberExpression :
	public TermExpression
{
public:
	NumberExpression(Context *const &context);
	NumberExpression(Context *const &context,const double &value);
	virtual ~NumberExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;
	virtual const std::string toString() const override;

	const double getValue() const;
	void setValue(const double &value);
protected:
	double value;
};

