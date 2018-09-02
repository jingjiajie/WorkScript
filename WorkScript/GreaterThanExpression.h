#pragma once
#include <memory>
#include "TypeExpression.h"
#include "BooleanExpression.h"
#include "DoubleExpression.h"
#include "BinaryCompareExpression.h"

class GreaterThanExpression :
	public BinaryCompareExpression
{
public:
	inline GreaterThanExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		:BinaryCompareExpression(left,right)
	{
	}
	virtual ~GreaterThanExpression();

	//virtual bool match(const Pointer<Expression> &matchExpression, Context *const& context) const override;
	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

protected:
	virtual const Pointer<BooleanExpression> numberCompareNumber(Context *context, const Pointer<NumberExpression> &, const Pointer<NumberExpression> &)const override;
};