#pragma once
#include "BinaryCalculateExpression.h"

class StringExpression;
class DoubleExpression;
class NumberExpression;

class MinusExpression :
	public BinaryCalculateExpression
{
public:
	inline MinusExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		:BinaryCalculateExpression(left, right)
	{

	}
	virtual ~MinusExpression();

	//virtual bool match(const Pointer<Expression> &matchExpression, Context *const& context) const override;
	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

private:
	virtual const Pointer<NumberExpression> numberCalcNumber(Context *const context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right)const override;
	//Pointer<StringExpression> stringMinusString(const Pointer<StringExpression>&, const Pointer<StringExpression>&) const;
};

