#pragma once
#include "BinaryCalculateExpression.h"
class ModulusExpression :
	public BinaryCalculateExpression
{
public:
	inline ModulusExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryCalculateExpression(left, right, level)
	{

	}

	inline ModulusExpression(const StorageLevel level = StorageLevel::TEMP)
		: BinaryCalculateExpression(level)
	{

	}

	virtual ~ModulusExpression();

	virtual StringExpression *const toString(Context *const& context) override;
	virtual TypeExpression* const getType(Context *const& context) const override;

protected:
	virtual NumberExpression * const numberCalcNumber(Context *const context, NumberExpression* const &left, NumberExpression* const &right)const;
};