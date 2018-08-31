#pragma once
#include "BinaryOperatorExpression.h"
#include "DoubleExpression.h"

class DivideExpression :
	public BinaryOperatorExpression
{
public:
	inline DivideExpression(const StorageLevel level = StorageLevel::TEMP)
		:BinaryOperatorExpression(level)
	{
	}

	inline DivideExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryOperatorExpression(left,right,level)
	{

	}
	virtual ~DivideExpression();

    virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	inline virtual TypeExpression* const getType(Context *const& context) const override {
		return &TypeExpression::DIVIDE_EXPRESSION;
	}
	virtual StringExpression *const toString(Context *const& context) override;

private:
	NumberExpression *const numberDivideNumber(NumberExpression* const&, NumberExpression* const&) const;
};

