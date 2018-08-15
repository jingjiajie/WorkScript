#include "EqualExpression.h"
#include "TypeExpression.h"
#include "BooleanExpression.h"

using namespace std;

EqualExpression::EqualExpression()
{
}


EqualExpression::~EqualExpression()
{
}

const std::shared_ptr<TypeExpression> EqualExpression::getType() const
{
	return TypeExpression::EQUAL_EXPRESSION;
}

const std::string EqualExpression::toString() const
{
	return this->leftExpression->toString() + " == " + this->rightExpression->toString();
}

const std::shared_ptr<TermExpression> EqualExpression::evaluate(Context * context)
{
	bool eq = this->leftExpression->evaluate(context)->equals(this->rightExpression->evaluate(context));
	return shared_ptr<BooleanExpression>(new BooleanExpression(eq));
}

bool EqualExpression::equals(const std::shared_ptr<TermExpression> &targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType())) {
		return false;
	}
	auto targetEqualExpression = dynamic_pointer_cast<EqualExpression>(targetExpression);
	return this->leftExpression->equals(targetEqualExpression->leftExpression)
		&& this->rightExpression->equals(targetEqualExpression->rightExpression);
}
