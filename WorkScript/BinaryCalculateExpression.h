#pragma once
#include "BinaryOperatorExpression.h"
class BinaryCalculateExpression :
	public BinaryOperatorExpression
{
public:
	inline BinaryCalculateExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryOperatorExpression(left, right, level)
	{

	}

	inline BinaryCalculateExpression(const StorageLevel level = StorageLevel::TEMP)
		: BinaryOperatorExpression(level)
	{

	}
	virtual ~BinaryCalculateExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	virtual StringExpression *const toString(Context *const& context) override = 0;

protected:
	virtual NumberExpression * const numberCalcNumber(Context *const context, NumberExpression* const &left, NumberExpression* const &right)const = 0;
	virtual Expression * const expressionCalcExpression(Context *context, Expression* const &left, Expression* const &right);
};

