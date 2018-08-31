#pragma once
#include "PointerExpression.h"
class BytePointerExpression :
	public PointerExpression
{
public:
	inline BytePointerExpression(const StorageLevel level = StorageLevel::TEMP)
		:PointerExpression(level)
	{
	}
	virtual ~BytePointerExpression();
};

