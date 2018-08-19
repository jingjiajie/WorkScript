#pragma once
#include "BinaryTermExpression.h"
class EqualExpression :
	public BinaryTermExpression
{
public:
	inline EqualExpression(const StorageLevel level = StorageLevel::TEMP)
		:BinaryTermExpression(level)
	{

	}

	virtual ~EqualExpression();

	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

	virtual Expression* const evaluate(Context *const& context) override;
};