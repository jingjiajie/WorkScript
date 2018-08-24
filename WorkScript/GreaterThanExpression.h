#pragma once
#include <memory>
#include "TypeExpression.h"
#include "BooleanExpression.h"
#include "NumberExpression.h"
#include "CompareExpression.h"

class GreaterThanExpression :
	public CompareExpression
{
public:
	inline GreaterThanExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:CompareExpression(left,right,level)
	{
	}
	virtual ~GreaterThanExpression();

	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

protected:
	virtual BooleanExpression* const numberCompareNumber(Context *context, NumberExpression* const&, NumberExpression* const&)const override;
};