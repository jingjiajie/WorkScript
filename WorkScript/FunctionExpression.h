#pragma once
#include "PolynomialExpression.h"
class FunctionExpression :
	public PolynomialExpression
{
public:
	FunctionExpression(Context *const &context,bool direct, const std::vector<std::shared_ptr<const Expression>> &subExpressions);
	FunctionExpression(Context *const &context, bool direct);
	virtual ~FunctionExpression();

	virtual std::shared_ptr<PolynomialExpression> newInstance() const override;

	virtual const std::shared_ptr<const TypeExpression> getType() const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual const std::string toString() const override;
private:
	bool direct;
	std::shared_ptr<const TypeExpression> type;
};

