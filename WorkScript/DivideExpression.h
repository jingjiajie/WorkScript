#pragma once
#include "BinaryCalculateExpression.h"
#include "DoubleExpression.h"

class DivideExpression :
	public BinaryCalculateExpression
{
public:
	inline DivideExpression()
		:BinaryCalculateExpression()
	{
	}

	inline DivideExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		: BinaryCalculateExpression(left,right)
	{
	}
	virtual ~DivideExpression();

	//virtual bool match(const Pointer<Expression> &matchExpression, Context *const& context) const override;
	inline virtual const Pointer<TypeExpression> getType(Context *const& context) const override {
		return TypeExpression::DIVIDE_EXPRESSION;
	}
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

private:
	virtual const Pointer<NumberExpression> numberCalcNumber(Context *const context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right)const override;
};