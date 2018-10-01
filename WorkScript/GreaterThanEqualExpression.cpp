#include "stdafx.h"
#include "GreaterThanEqualExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "DoubleExpression.h"

GreaterThanEqualExpression::~GreaterThanEqualExpression()
{
}

const Pointer<TypeExpression> GreaterThanEqualExpression::getType(Context * const & context) const
{
	return TypeExpression::GREATER_THAN_EQUAL_EXPRESSION;
}

const Pointer<StringExpression> GreaterThanEqualExpression::toString(Context * const & context)
{
	static Pointer<StringExpression> sign = new StringExpression(L">=", ReleaseStrategy::DELETE);
	return BinaryOperatorExpression::toString(context, sign);
}

const Pointer<BooleanExpression> GreaterThanEqualExpression::numberCompareNumber(Context * context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right) const
{
	return left->greaterThanEquals(right);
}
