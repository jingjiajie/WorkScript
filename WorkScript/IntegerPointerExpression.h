#pragma once
#include "PointerExpression.h"
class IntegerPointerExpression :
	public PointerExpression
{
public:
	inline IntegerPointerExpression() 
		:PointerExpression()
	{

	}
	virtual ~IntegerPointerExpression();
};

