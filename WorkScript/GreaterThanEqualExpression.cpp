#include "GreaterThanEqualExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "NumberExpression.h"

GreaterThanEqualExpression::~GreaterThanEqualExpression()
{
}

TypeExpression * const GreaterThanEqualExpression::getType(Context * const & context) const
{
	return &TypeExpression::GREATER_THAN_EQUAL_EXPRESSION;
}

StringExpression * const GreaterThanEqualExpression::toString(Context * const & context)
{
	static StringExpression sign(">=",StorageLevel::EXTERN);
	return BinaryExpression::toString(context, &sign);
}

BooleanExpression * const GreaterThanEqualExpression::numberCompareNumber(Context * context, NumberExpression * const &left, NumberExpression * const &right) const
{
	return BooleanExpression::newInstance(left->getValue() >= right->getValue());
}
