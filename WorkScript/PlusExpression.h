#pragma once
#include "BinaryOperatorExpression.h"

class NumberExpression;
class StringExpression;

class PlusExpression :
	public BinaryOperatorExpression
{
public:
	inline PlusExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryOperatorExpression(left,right,level) 
	{

	}
	inline PlusExpression(const StorageLevel level = StorageLevel::TEMP)
		:BinaryOperatorExpression(level) 
	{

	}
	virtual ~PlusExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

private:
	NumberExpression * numberPlusNumber(Context *const &context, NumberExpression* const&,NumberExpression* const&) const;
	StringExpression * exprPlusExpr(Context *const &context, Expression* const&, Expression* const&) const;
};

