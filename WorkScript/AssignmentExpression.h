#pragma once
#include "BinaryExpression.h"
class AssignmentExpression :
	public BinaryExpression
{
public:
	inline AssignmentExpression(const StorageLevel level)
		:BinaryExpression(level)
	{
	}

	inline AssignmentExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		: BinaryExpression(left, right, level)
	{
	}

	virtual ~AssignmentExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;
};

