#pragma once
#include "NumberExpression.h"
#include "StringExpression.h"
#include "BinaryOperatorExpression.h"
class MultiplyExpression :
	public BinaryOperatorExpression
{
public:
	inline MultiplyExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryOperatorExpression(left, right, level) 
	{

	}
	MultiplyExpression(const StorageLevel level = StorageLevel::TEMP)
		:BinaryOperatorExpression(level) 
	{

	}
	virtual ~MultiplyExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

private:
	NumberExpression * numberMultiplyNumber(Context *const &context, NumberExpression* const&, NumberExpression* const&) const;
	StringExpression * stringMultiplyNumber(Context *const &context, StringExpression* const&, NumberExpression* const&) const;
};

