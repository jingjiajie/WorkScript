#pragma once
#include "BinaryCompareExpression.h"
class LessThanExpression :
	public BinaryCompareExpression
{
public:
	inline LessThanExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		:BinaryCompareExpression(left, right)
	{

	}
	virtual ~LessThanExpression();

	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

protected:
	virtual const Pointer<BooleanExpression> numberCompareNumber(Context *context, const Pointer<NumberExpression> &, const Pointer<NumberExpression> &)const override;
};

