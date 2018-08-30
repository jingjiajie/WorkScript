#include "NegativeExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "NumberExpression.h"
#include "UncalculatableException.h"
#include <boost/locale.hpp>

using namespace std;

NegativeExpression::~NegativeExpression()
{
}

Expression * const NegativeExpression::evaluate(Context * const & context)
{
	TempExpression<Expression> evaluatedSub(this->subExpression, this->subExpression->evaluate(context));
	if (evaluatedSub->getType(context)->equals(context, &TypeExpression::NUMBER_EXPRESSION)) {
		return NumberExpression::newInstance(-1 * ((NumberExpression*)evaluatedSub.getExpression())->getValue());
	}
	else {
		TempExpression<StringExpression> str(evaluatedSub,evaluatedSub->toString(context));
		throw std::move(UncalculatableException((wstring(str->getValue()) + L"无法取负！").c_str()));
	}
}

TypeExpression * const NegativeExpression::getType(Context * const & context) const
{
	return &TypeExpression::NEGATIVE_EXPRESSION;
}

StringExpression * const NegativeExpression::toString(Context * const & context)
{
	static StringExpression sign(L"-",StorageLevel::EXTERN);
	return UnaryOperatorExpression::toString(context, &sign);
}
