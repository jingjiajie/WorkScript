#pragma once
#include "BinaryCompareExpression.h"
class EqualsExpression :
	public BinaryCompareExpression
{
public:
	inline EqualsExpression(const StorageLevel level = StorageLevel::TEMP)
		:BinaryCompareExpression(level)
	{

	}

	inline EqualsExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		: BinaryCompareExpression(left,right,level)
	{

	}

	virtual ~EqualsExpression();

	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

protected:
	virtual BooleanExpression * const numberCompareNumber(Context *context, NumberExpression* const&, NumberExpression* const&)const override;
	virtual BooleanExpression * const expressionCompareExpression(Context *context, Expression* const&, Expression* const&)const;
};