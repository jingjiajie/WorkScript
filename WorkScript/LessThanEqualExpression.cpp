#include "LessThanEqualExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "DoubleExpression.h"

LessThanEqualExpression::~LessThanEqualExpression()
{
}

const Pointer<TypeExpression> LessThanEqualExpression::getType(Context * const & context) const
{
	return TypeExpression::LESS_THAN_EQUAL_EXPRESSION;
}

const Pointer<StringExpression> LessThanEqualExpression::toString(Context * const & context)
{
	static Pointer<StringExpression> sign = new StringExpression(L"<=", ReleaseStrategy::DELETE);
	return BinaryOperatorExpression::toString(context, sign);
}

const Pointer<BooleanExpression> LessThanEqualExpression::numberCompareNumber(Context * context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right) const
{
	return left->lessThanEquals(right);
}
