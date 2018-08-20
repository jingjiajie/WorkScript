#pragma once
#include "BinaryTermExpression.h"
class AssignmentExpression :
	public BinaryTermExpression
{
public:
	inline AssignmentExpression(const StorageLevel level)
		:BinaryTermExpression(level)
	{
	}

	inline AssignmentExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		: BinaryTermExpression(left, right, level)
	{
	}

	virtual ~AssignmentExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;
};

