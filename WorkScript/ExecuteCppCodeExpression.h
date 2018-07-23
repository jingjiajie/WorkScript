#pragma once
#include <memory>
#include <functional>
#include "PolynomialExpression.h"
class ExecuteCppCodeExpression :
	public PolynomialExpression
{
public:
	ExecuteCppCodeExpression(Context *const &context,const std::function<const std::shared_ptr<const Expression>(const ExpressionBind&)> &evaluateFunction);
	virtual ~ExecuteCppCodeExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;

protected:
	std::function<const std::shared_ptr<const Expression>(const ExpressionBind&)> evaluateFunction;
};

