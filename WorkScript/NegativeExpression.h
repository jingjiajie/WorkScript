#pragma once
#include "UnaryOperatorExpression.h"
class NegativeExpression :
	public UnaryOperatorExpression
{
public:
	inline NegativeExpression(Expression* const &subExpression, const StorageLevel level = StorageLevel::TEMP)
		:UnaryOperatorExpression(subExpression,level)
	{

	}

	inline NegativeExpression(const StorageLevel level = StorageLevel::TEMP)
		: UnaryOperatorExpression(level)
	{

	}

	virtual ~NegativeExpression();

	virtual Expression* const evaluate(Context *const& context);
	virtual TypeExpression* const getType(Context *const& context) const;
	virtual StringExpression *const toString(Context *const& context);
};

