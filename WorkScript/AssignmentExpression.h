#pragma once
#include "BinaryOperatorExpression.h"
class AssignmentExpression :
	public BinaryOperatorExpression
{
public:
	inline AssignmentExpression(const StorageLevel level)
		:BinaryOperatorExpression(level)
	{
	}

	inline AssignmentExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		: BinaryOperatorExpression(left, right, level)
	{
	}

	virtual ~AssignmentExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

	virtual AssignmentExpression *const evaluateParamAssignment(Context *const &context);
};

