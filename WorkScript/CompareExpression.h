#pragma once
#include "BinaryOperatorExpression.h"

class BooleanExpression;
class NumberExpression;
class VariableExpression;

class CompareExpression :
	public BinaryOperatorExpression
{
public:
	inline CompareExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
		:BinaryOperatorExpression(left, right, level)
	{

	}

	inline CompareExpression(const StorageLevel level = StorageLevel::TEMP)
		: BinaryOperatorExpression(level)
	{

	}
	virtual ~CompareExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	
	inline VariableExpression *const getLeftVariable() const 
	{
		if (this->leftExpression->getType(nullptr)->equals(nullptr, &TypeExpression::VARIABLE_EXPRESSION)) {
			return (VariableExpression *&)this->leftExpression;
		}
		else {
			return nullptr;
		}
	}
protected:
	virtual BooleanExpression * const numberCompareNumber(Context *context, NumberExpression* const &left, NumberExpression* const &right)const = 0;
	virtual BooleanExpression * const expressionCompareExpression(Context *context, Expression* const &left, Expression* const &right)const;
};

