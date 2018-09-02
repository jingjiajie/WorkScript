#pragma once
#include "UnaryOperatorExpression.h"
class NegativeExpression :
	public UnaryOperatorExpression
{
public:
	inline NegativeExpression(const Pointer<Expression> &subExpression)
		:UnaryOperatorExpression(subExpression)
	{

	}

	inline NegativeExpression()
		: UnaryOperatorExpression()
	{

	}

	virtual ~NegativeExpression();

	virtual const Pointer<Expression> evaluate(Context *const& context);
	virtual const Pointer<TypeExpression> getType(Context *const& context) const;
	virtual const Pointer<StringExpression> toString(Context *const& context);
};

