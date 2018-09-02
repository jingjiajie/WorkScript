#include "NegativeExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "DoubleExpression.h"
#include "UncalculatableException.h"
#include <boost/locale.hpp>

using namespace std;

NegativeExpression::~NegativeExpression()
{
}

const Pointer<Expression> NegativeExpression::evaluate(Context * const & context)
{
	Pointer<Expression> evaluatedSub =  this->subExpression->evaluate(context);
	if (evaluatedSub->getType(context)->equals(context, TypeExpression::NUMBER_EXPRESSION)) {
		return DoubleExpression::newInstance(-1 * ((Pointer<DoubleExpression>)evaluatedSub)->getValue());
	}
	else {
		Pointer<StringExpression> str = evaluatedSub->toString(context);
		throw std::move(UncalculatableException((wstring(str->getValue()) + L"无法取负！").c_str()));
	}
}

const Pointer<TypeExpression> NegativeExpression::getType(Context * const & context) const
{
	return TypeExpression::NEGATIVE_EXPRESSION;
}

const Pointer<StringExpression> NegativeExpression::toString(Context * const & context)
{
	static Pointer<StringExpression> sign = new StringExpression(L"-", ReleaseStrategy::DELETE);
	return UnaryOperatorExpression::toString(context, sign);
}
