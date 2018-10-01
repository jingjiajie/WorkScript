#include "stdafx.h"
#include "LessThanExpression.h"
#include "StringExpression.h"
#include "BooleanExpression.h"
#include "DoubleExpression.h"

LessThanExpression::~LessThanExpression()
{
}

const Pointer<TypeExpression> LessThanExpression::getType(Context * const & context) const
{
	return TypeExpression::LESS_THAN_EXPRESSION;
}

const Pointer<StringExpression> LessThanExpression::toString(Context * const & context)
{
	static Pointer<StringExpression> sign = new StringExpression(L">", ReleaseStrategy::DELETE);
	return BinaryOperatorExpression::toString(context, sign);
}

const Pointer<BooleanExpression> LessThanExpression::numberCompareNumber(Context * context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right) const
{
	return left->lessThan(right);
}
