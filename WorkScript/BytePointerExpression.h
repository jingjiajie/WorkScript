#pragma once
#include "PointerExpression.h"
class BytePointerExpression :
	public PointerExpression
{
public:
	inline BytePointerExpression()
		:PointerExpression()
	{
	}
	virtual ~BytePointerExpression();
};

