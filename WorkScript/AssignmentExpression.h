#pragma once
#include "BinaryOperatorExpression.h"
class AssignmentExpression :
	public BinaryOperatorExpression
{
public:
	inline AssignmentExpression()
		:BinaryOperatorExpression()
	{
	}

	inline AssignmentExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		: BinaryOperatorExpression(left, right)
	{
	}

	virtual ~AssignmentExpression();

	virtual const Pointer<Expression> evaluate(Context *const& context) override;
	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

	virtual const Pointer<AssignmentExpression> evaluateParamAssignment(Context *const &context);
};

