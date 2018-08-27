#include "EqualsExpression.h"
#include "TypeExpression.h"
#include "BooleanExpression.h"
#include "Program.h"
#include "StringExpression.h"
#include "NumberExpression.h"

using namespace std;

EqualsExpression::~EqualsExpression()
{
}

TypeExpression* const EqualsExpression::getType(Context *const& context) const
{
	return &TypeExpression::EQUALS_EXPRESSION;
}

StringExpression *const EqualsExpression::toString(Context *const& context)
{
	static StringExpression equal("==", StorageLevel::EXTERN);
	return BinaryOperatorExpression::toString(context, &equal);
}

BooleanExpression * const EqualsExpression::numberCompareNumber(Context * context, NumberExpression * const &left, NumberExpression * const &right) const
{
	return BooleanExpression::newInstance(left->equals(context, right));
}

BooleanExpression * const EqualsExpression::expressionCompareExpression(Context * context, Expression * const &left, Expression * const &right) const
{
	return BooleanExpression::newInstance(left->equals(context, right));
}
