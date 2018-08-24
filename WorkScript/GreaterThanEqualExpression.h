#pragma once
#include "CompareExpression.h"
class GreaterThanEqualExpression :
	public CompareExpression
{
public:
	inline GreaterThanEqualExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:CompareExpression(left, right, level)
	{

	}
	virtual ~GreaterThanEqualExpression();

	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

protected:
	virtual BooleanExpression* const numberCompareNumber(Context *context, NumberExpression* const&, NumberExpression* const&)const override;
};

