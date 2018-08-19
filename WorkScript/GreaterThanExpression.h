#pragma once
#include <memory>
#include "BinaryTermExpression.h"
#include "TypeExpression.h"
#include "BooleanExpression.h"
#include "NumberExpression.h"

class GreaterThanExpression :
	public BinaryTermExpression
{
public:
	inline GreaterThanExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryTermExpression(left,right,level)
	{
	}
	virtual ~GreaterThanExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

protected:
	BooleanExpression* const numberGreaterThanNumber(NumberExpression* const&, NumberExpression* const&)const;
};