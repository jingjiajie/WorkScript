#pragma once
#include "BinaryExpression.h"
#include "NumberExpression.h"

class DivideExpression :
	public BinaryExpression
{
public:
	inline DivideExpression(const StorageLevel level = StorageLevel::TEMP)
		:BinaryExpression(level)
	{
	}

	inline DivideExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryExpression(left,right,level)
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

