#pragma once
#include "BinaryCompareExpression.h"
class EqualsExpression :
	public BinaryCompareExpression
{
public:
	inline EqualsExpression()
		:BinaryCompareExpression()
	{

	}

	inline EqualsExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		: BinaryCompareExpression(left,right)
	{

	}

	virtual ~EqualsExpression();

	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

protected:
	virtual const Pointer<BooleanExpression> numberCompareNumber(Context *context, const Pointer<NumberExpression> &, const Pointer<NumberExpression> &)const override;
	virtual const Pointer<BooleanExpression> expressionCompareExpression(Context *context, const Pointer<Expression> &, const Pointer<Expression> &)const;
};