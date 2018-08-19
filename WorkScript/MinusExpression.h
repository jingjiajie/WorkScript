#pragma once
#include "BinaryTermExpression.h"

class StringExpression;
class NumberExpression;

class MinusExpression :
	public BinaryTermExpression
{
public:
	inline MinusExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryTermExpression(left, right, level) 
	{

	}
	virtual ~MinusExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

private:
	NumberExpression * numberMinusNumber(NumberExpression* const&, NumberExpression* const&) const;
	StringExpression * stringMinusNumber(StringExpression* const&, NumberExpression* const&) const;
	//StringExpression * stringMinusString(StringExpression* const&, StringExpression* const&) const;
};

