#pragma once
#include "BinaryCalculateExpression.h"

class StringExpression;
class DoubleExpression;
class NumberExpression;

class MinusExpression :
	public BinaryCalculateExpression
{
public:
	inline MinusExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryCalculateExpression(left, right, level)
	{

	}
	virtual ~MinusExpression();

	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

private:
	virtual NumberExpression * const numberCalcNumber(Context *const context, NumberExpression* const &left, NumberExpression* const &right)const override;
	//StringExpression * stringMinusString(StringExpression* const&, StringExpression* const&) const;
};

