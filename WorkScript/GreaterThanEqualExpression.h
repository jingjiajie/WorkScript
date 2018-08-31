#pragma once
#include "BinaryCompareExpression.h"
class GreaterThanEqualExpression :
	public BinaryCompareExpression
{
public:
	inline GreaterThanEqualExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryCompareExpression(left, right, level)
	{

	}
	virtual ~GreaterThanEqualExpression();

	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

protected:
	virtual BooleanExpression* const numberCompareNumber(Context *context, NumberExpression* const&, NumberExpression* const&)const override;
};

