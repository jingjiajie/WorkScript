#pragma once
#include "BinaryCalculateExpression.h"

class DoubleExpression;
class StringExpression;

class PlusExpression :
	public BinaryCalculateExpression
{
public:
	inline PlusExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		:BinaryCalculateExpression(left,right)
	{

	}
	inline PlusExpression()
		: BinaryCalculateExpression()
	{

	}
	virtual ~PlusExpression();

	//virtual bool match(const Pointer<Expression> &matchExpression, Context *const& context) const override;
	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

private:
	virtual const Pointer<NumberExpression> numberCalcNumber(Context *const context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right)const override;
	virtual const Pointer<Expression> expressionCalcExpression(Context *context, const Pointer<Expression> &left, const Pointer<Expression> &right) override;
};

