#pragma once
#include "Expression.h"
class PolynomialExpression :
	public Expression
{
public:
	PolynomialExpression(Context *const &context);
	virtual ~PolynomialExpression();

	virtual const std::shared_ptr<const Expression> matchFirstUpInContextAndEvaluate(const std::shared_ptr<const Expression>&) const;
};