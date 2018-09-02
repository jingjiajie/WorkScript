#include "EqualsExpression.h"
#include "TypeExpression.h"
#include "BooleanExpression.h"
#include "Program.h"
#include "StringExpression.h"
#include "DoubleExpression.h"

using namespace std;

EqualsExpression::~EqualsExpression()
{
}

const Pointer<TypeExpression> EqualsExpression::getType(Context *const& context) const
{
	return TypeExpression::EQUALS_EXPRESSION;
}

const Pointer<StringExpression> EqualsExpression::toString(Context *const& context)
{
	static Pointer<StringExpression> equal(new StringExpression(L"==", ReleaseStrategy::DELETE));
	return BinaryOperatorExpression::toString(context, equal);
}

const Pointer<BooleanExpression> EqualsExpression::numberCompareNumber(Context * context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right) const
{
	return left->equals(right);
}

const Pointer<BooleanExpression> EqualsExpression::expressionCompareExpression(Context * context, const Pointer<Expression> &left, const Pointer<Expression> &right) const
{
	return BooleanExpression::newInstance(left->equals(context, right));
}
