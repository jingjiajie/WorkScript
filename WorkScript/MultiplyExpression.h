#pragma once
#include "DoubleExpression.h"
#include "StringExpression.h"
#include "BinaryCalculateExpression.h"
class MultiplyExpression :
	public BinaryCalculateExpression
{
public:
	inline MultiplyExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryCalculateExpression(left, right, level)
	{

	}
	MultiplyExpression(const StorageLevel level = StorageLevel::TEMP)
		:BinaryCalculateExpression(level)
	{

	}
	virtual ~MultiplyExpression();

	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

private:
	virtual NumberExpression * const numberCalcNumber(Context *const context, NumberExpression* const &left, NumberExpression* const &right)const override;
	//StringExpression * stringMultiplyNumber(Context *const &context, StringExpression* const&, NumberExpression* const&) const;
};

