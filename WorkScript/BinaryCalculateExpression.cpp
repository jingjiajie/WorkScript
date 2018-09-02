#include "BinaryCalculateExpression.h"
#include "UncalculatableException.h"
#include "NumberExpression.h"
#include <wchar.h>
#include <string>

using namespace std;

BinaryCalculateExpression::~BinaryCalculateExpression()
{
}

const Pointer<Expression> BinaryCalculateExpression::evaluate(Context * const & context)
{
	Pointer<Expression> evaluatedLeft =  this->leftExpression->evaluate(context);
	Pointer<Expression> evaluatedRight =  this->rightExpression->evaluate(context);
	if (evaluatedLeft->getType(nullptr)->isSubTypeOf(context, TypeExpression::NUMBER_EXPRESSION) && evaluatedRight->getType(nullptr)->isSubTypeOf(context, TypeExpression::NUMBER_EXPRESSION)) {
		return this->numberCalcNumber(context, (const Pointer<NumberExpression>)(evaluatedLeft), (const Pointer<NumberExpression>)(evaluatedRight));
	}
	else {
		return this->expressionCalcExpression(context, evaluatedLeft, evaluatedRight);
	}
}

const Pointer<Expression> BinaryCalculateExpression::expressionCalcExpression(Context * context, const Pointer<Expression> & left, const Pointer<Expression> & right)
{
	Pointer<StringExpression> str =  this->toString(context);
	throw UncalculatableException((wstring(str->getValue()) + L"Œﬁ∑®º∆À„£°").c_str());
}
