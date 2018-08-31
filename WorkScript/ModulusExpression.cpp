#include "ModulusExpression.h"
#include "NumberExpression.h"
#include "TypeExpression.h"

ModulusExpression::~ModulusExpression()
{
}

StringExpression * const ModulusExpression::toString(Context * const & context)
{
	static StringExpression mod(L"%",StorageLevel::EXTERN);
	return BinaryOperatorExpression::toString(context, &mod);
}

TypeExpression * const ModulusExpression::getType(Context * const & context) const
{
	return &TypeExpression::MODULUS_EXPRESSION;
}

NumberExpression * const ModulusExpression::numberCalcNumber(Context * const context, NumberExpression * const & left, NumberExpression * const & right) const
{
	return left->modulus(right);
}
