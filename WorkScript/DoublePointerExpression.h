#pragma once
#include "PointerExpression.h"
class DoublePointerExpression :
	public PointerExpression
{
public:
	inline DoublePointerExpression(const StorageLevel level = StorageLevel::TEMP)
		:PointerExpression(level)
	{

	}
	virtual ~DoublePointerExpression();
};

