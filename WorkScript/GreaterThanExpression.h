#pragma once
#include <memory>
#include "TypeExpression.h"
#include "BooleanExpression.h"
#include "DoubleExpression.h"
#include "BinaryCompareExpression.h"

class GreaterThanExpression :
	public BinaryCompareExpression
{
public:
	inline GreaterThanExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryCompareExpression(left,right,level)
	{
	}
	virtual ~GreaterThanExpression();

	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

protected:
	virtual BooleanExpression* const numberCompareNumber(Context *context, NumberExpression* const&, NumberExpression* const&)const override;
};