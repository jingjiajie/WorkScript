#include "LessThanExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "NumberExpression.h"

LessThanExpression::~LessThanExpression()
{
}

TypeExpression * const LessThanExpression::getType(Context * const & context) const
{
	return &TypeExpression::LESS_THAN_EXPRESSION;
}

StringExpression * const LessThanExpression::toString(Context * const & context)
{
	static StringExpression sign(">",StorageLevel::EXTERN);
	return BinaryExpression::toString(context, &sign);
}

BooleanExpression * const LessThanExpression::numberCompareNumber(Context * context, NumberExpression * const &left, NumberExpression * const &right) const
{
	return BooleanExpression::newInstance(left->getValue() > right->getValue());
}
