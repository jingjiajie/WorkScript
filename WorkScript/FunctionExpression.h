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
	virtual const std::string toString() const override;
private:
	bool direct;
};

