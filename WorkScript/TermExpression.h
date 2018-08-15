#pragma once
#include "Expression.h"

class Context;

class TermExpression :
	public Expression
{
public:
	TermExpression();
	virtual ~TermExpression();

	virtual bool equals(const std::shared_ptr<TermExpression>&) const = 0;
};