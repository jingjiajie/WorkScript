#pragma once
#include "TermExpression.h"
class BooleanExpression :
	public TermExpression
{
public:
	BooleanExpression(Context *const &context);
	BooleanExpression(Context *const &context, const bool &value);
	virtual ~BooleanExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;
	virtual const std::string toString() const override;

	const bool getValue() const;
	void setValue(const bool &value);
protected:
	bool value;
	std::shared_ptr<const TypeExpression> type;
};

