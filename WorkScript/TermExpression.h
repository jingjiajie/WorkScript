#pragma once
#include "ValueExpression.h"
class TermExpression :
	public ValueExpression
{
public:
	TermExpression(Context *const &context);
	virtual ~TermExpression();
};

