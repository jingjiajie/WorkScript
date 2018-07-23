#pragma once
#include "PolynomialExpression.h"
class ThisExpression :
	public PolynomialExpression
{
public:
	ThisExpression(Context *const &context);
	virtual ~ThisExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;
};

