#pragma once
#include "BinaryCalculateExpression.h"
class ModulusExpression :
	public BinaryCalculateExpression
{
public:
	inline ModulusExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		:BinaryCalculateExpression(left, right)
	{

	}

	inline ModulusExpression()
		: BinaryCalculateExpression()
	{

	}

	virtual ~ModulusExpression();

	virtual const Pointer<StringExpression> toString(Context *const& context) override;
	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;

protected:
	virtual const Pointer<NumberExpression> numberCalcNumber(Context *const context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right)const;
};