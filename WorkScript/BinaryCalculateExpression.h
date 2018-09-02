#pragma once
#include "BinaryOperatorExpression.h"
class BinaryCalculateExpression :
	public BinaryOperatorExpression
{
public:
	inline BinaryCalculateExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		:BinaryOperatorExpression(left, right)
	{

	}

	inline BinaryCalculateExpression()
		: BinaryOperatorExpression()
	{

	}
	virtual ~BinaryCalculateExpression();

	virtual const Pointer<Expression> evaluate(Context *const& context) override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override = 0;

protected:
	virtual const Pointer<NumberExpression> numberCalcNumber(Context *const context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right)const = 0;
	virtual const Pointer<Expression> expressionCalcExpression(Context *context, const Pointer<Expression> &left, const Pointer<Expression> &right);
};

