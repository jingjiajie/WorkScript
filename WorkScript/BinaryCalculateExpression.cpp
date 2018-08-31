#include "BinaryCalculateExpression.h"
#include "UncalculatableException.h"
#include "NumberExpression.h"
#include <wchar.h>
#include <string>

using namespace std;

BinaryCalculateExpression::~BinaryCalculateExpression()
{
}

Expression * const BinaryCalculateExpression::evaluate(Context * const & context)
{
	TempExpression<Expression> evaluatedLeft(this->leftExpression, this->leftExpression->evaluate(context));
	TempExpression<Expression> evaluatedRight(this->rightExpression, this->rightExpression->evaluate(context));
	if (evaluatedLeft->getType(nullptr)->isSubTypeOf(context, &TypeExpression::NUMBER_EXPRESSION) && evaluatedRight->getType(nullptr)->isSubTypeOf(context, &TypeExpression::NUMBER_EXPRESSION)) {
		return this->numberCalcNumber(context, (NumberExpression *const)(evaluatedLeft), (NumberExpression *const)(evaluatedRight));
	}
	else {
		return this->expressionCalcExpression(context, evaluatedLeft, evaluatedRight);
	}
}

Expression * const BinaryCalculateExpression::expressionCalcExpression(Context * context, Expression * const & left, Expression * const & right)
{
	TempExpression<StringExpression> str(this, this->toString(context));
	throw UncalculatableException((wstring(str->getValue()) + L"Œﬁ∑®º∆À„£°").c_str());
}
