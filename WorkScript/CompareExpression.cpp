#include "BinaryCompareExpression.h"
#include "BooleanExpression.h"
#include "UncomparableException.h"
#include <boost/locale.hpp>
#include <string>

using namespace std;

BinaryCompareExpression::~BinaryCompareExpression()
{
}

Expression * const BinaryCompareExpression::evaluate(Context * const & context)
{
	TempExpression<Expression> evaluatedLeft(this->leftExpression, this->leftExpression->evaluate(context));
	TempExpression<Expression> evaluatedRight(this->rightExpression, this->rightExpression->evaluate(context));
	if (evaluatedLeft->getType(nullptr)->isSubTypeOf(context, &TypeExpression::NUMBER_EXPRESSION) && evaluatedRight->getType(nullptr)->isSubTypeOf(context, &TypeExpression::NUMBER_EXPRESSION)) {
		return this->numberCompareNumber(context, (NumberExpression *const&)(evaluatedLeft), (NumberExpression *const&)(evaluatedRight));
	}
	else {
		return this->expressionCompareExpression(context, evaluatedLeft, evaluatedRight);
	}
}

BooleanExpression * const BinaryCompareExpression::expressionCompareExpression(Context *context, Expression * const &left, Expression * const &right) const
{
	TempExpression<StringExpression> leftStrExpr(left, left->toString(context));
	TempExpression<StringExpression> rightStrExpr(right, right->toString(context));
	throw UncomparableException((wstring(leftStrExpr->getValue()) + L" 和 " + rightStrExpr->getValue() + L"无法比较！").c_str());
}
