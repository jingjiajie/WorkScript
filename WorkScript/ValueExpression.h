#pragma once
#include "Expression.h"
class ValueExpression :
	public Expression
{
public:
	ValueExpression(Context *const &context);
	virtual ~ValueExpression();

	virtual const std::shared_ptr<const Expression> matchFirstUpInContextAndEvaluate(const std::shared_ptr<const Expression>&) const;
};