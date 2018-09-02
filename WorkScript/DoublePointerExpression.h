#pragma once
#include "PointerExpression.h"
class DoublePointerExpression :
	public PointerExpression
{
public:
	inline DoublePointerExpression()
		:PointerExpression()
	{

	}
	virtual ~DoublePointerExpression();
};

