#include "stdafx.h"
#include "BinaryCompareExpression.h"
#include "BooleanExpression.h"
#include "UncomparableException.h"

using namespace std;

BinaryCompareExpression::~BinaryCompareExpression()
{
}

const Pointer<Expression> BinaryCompareExpression::evaluate(Context * const & context)
{
	Pointer<Expression> evaluatedLeft =  this->leftExpression->evaluate(context);
	Pointer<Expression> evaluatedRight =  this->rightExpression->evaluate(context);
	if (evaluatedLeft->getType(nullptr)->isSubTypeOf(context, TypeExpression::NUMBER_EXPRESSION) && evaluatedRight->getType(nullptr)->isSubTypeOf(context, TypeExpression::NUMBER_EXPRESSION)) {
		return this->numberCompareNumber(context, (const Pointer<NumberExpression> &)(evaluatedLeft), (const Pointer<NumberExpression> &)(evaluatedRight));
	}
	else {
		return this->expressionCompareExpression(context, evaluatedLeft, evaluatedRight);
	}
}

const Pointer<BooleanExpression> BinaryCompareExpression::expressionCompareExpression(Context *context, const Pointer<Expression> &left, const Pointer<Expression> &right) const
{
	Pointer<StringExpression> leftStrExpr =  left->toString(context);
	Pointer<StringExpression> rightStrExpr =  right->toString(context);
	throw UncomparableException((wstring(leftStrExpr->getValue()) + L" 和 " + rightStrExpr->getValue() + L"无法比较！").c_str());
}
