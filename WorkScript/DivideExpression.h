#pragma once
#include "BinaryCalculateExpression.h"
#include "DoubleExpression.h"

class DivideExpression :
	public BinaryCalculateExpression
{
public:
	inline DivideExpression(const StorageLevel level = StorageLevel::TEMP)
		:BinaryCalculateExpression(level)
	{
	}

	inline DivideExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		: BinaryCalculateExpression(left,right,level)
	{
	}
	virtual ~DivideExpression();

	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	inline virtual TypeExpression* const getType(Context *const& context) const override {
		return &TypeExpression::DIVIDE_EXPRESSION;
	}
	virtual StringExpression *const toString(Context *const& context) override;

private:
	virtual NumberExpression * const numberCalcNumber(Context *const context, NumberExpression* const &left, NumberExpression* const &right)const override;
};