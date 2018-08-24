#include "LessThanEqualExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "NumberExpression.h"

LessThanEqualExpression::~LessThanEqualExpression()
{
}

TypeExpression * const LessThanEqualExpression::getType(Context * const & context) const
{
	return &TypeExpression::LESS_THAN_EQUAL_EXPRESSION;
}

StringExpression * const LessThanEqualExpression::toString(Context * const & context)
{
	static StringExpression sign("<=",StorageLevel::EXTERN);
	return BinaryExpression::toString(context, &sign);
}

BooleanExpression * const LessThanEqualExpression::numberCompareNumber(Context * context, NumberExpression * const &left, NumberExpression * const &right) const
{
	return BooleanExpression::newInstance(left->getValue() <= right->getValue());
}
