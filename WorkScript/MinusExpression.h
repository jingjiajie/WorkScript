#pragma once
#include "BinaryOperatorExpression.h"

class StringExpression;
class DoubleExpression;
class NumberExpression;

class MinusExpression :
	public BinaryOperatorExpression
{
public:
	inline MinusExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryOperatorExpression(left, right, level) 
	{

	}
	virtual ~MinusExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

private:
	NumberExpression * numberMinusNumber(NumberExpression* const&, NumberExpression* const&) const;
	//StringExpression * stringMinusString(StringExpression* const&, StringExpression* const&) const;
};

