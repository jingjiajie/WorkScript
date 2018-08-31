#pragma once
#include "BinaryCalculateExpression.h"

class DoubleExpression;
class StringExpression;

class PlusExpression :
	public BinaryCalculateExpression
{
public:
	inline PlusExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryCalculateExpression(left,right,level)
	{

	}
	inline PlusExpression(const StorageLevel level = StorageLevel::TEMP)
		: BinaryCalculateExpression(level)
	{

	}
	virtual ~PlusExpression();

	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context) override;

private:
	virtual NumberExpression * const numberCalcNumber(Context *const context, NumberExpression* const &left, NumberExpression* const &right)const override;
	//StringExpression * exprPlusExpr(Context *const &context, Expression* const&, Expression* const&) const;
};

