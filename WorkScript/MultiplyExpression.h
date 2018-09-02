#pragma once
#include "DoubleExpression.h"
#include "StringExpression.h"
#include "BinaryCalculateExpression.h"
class MultiplyExpression :
	public BinaryCalculateExpression
{
public:
	inline MultiplyExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		:BinaryCalculateExpression(left, right)
	{

	}
	MultiplyExpression()
		:BinaryCalculateExpression()
	{

	}
	virtual ~MultiplyExpression();

	//virtual bool match(const Pointer<Expression> &matchExpression, Context *const& context) const override;
	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

private:
	virtual const Pointer<NumberExpression> numberCalcNumber(Context *const context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right)const override;
	//Pointer<StringExpression> stringMultiplyNumber(Context *const &context, const Pointer<StringExpression>&, const Pointer<NumberExpression>&) const;
};

