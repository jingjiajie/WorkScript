#include "stdafx.h"
#include "ModulusExpression.h"
#include "NumberExpression.h"
#include "TypeExpression.h"

ModulusExpression::~ModulusExpression()
{
}

const Pointer<StringExpression> ModulusExpression::toString(Context * const & context)
{
	static Pointer<StringExpression> mod(new StringExpression(L"%", ReleaseStrategy::DELETE));
	return BinaryOperatorExpression::toString(context, mod);
}

const Pointer<TypeExpression> ModulusExpression::getType(Context * const & context) const
{
	return TypeExpression::MODULUS_EXPRESSION;
}

const Pointer<NumberExpression> ModulusExpression::numberCalcNumber(Context * const context, const Pointer<NumberExpression> & left, const Pointer<NumberExpression> & right) const
{
	return left->modulus(right);
}
