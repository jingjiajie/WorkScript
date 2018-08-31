#pragma once
#include "PointerExpression.h"
class IntegerPointerExpression :
	public PointerExpression
{
public:
	inline IntegerPointerExpression(const StorageLevel level = StorageLevel::TEMP) 
		:PointerExpression(level)
	{

	}
	virtual ~IntegerPointerExpression();
};

