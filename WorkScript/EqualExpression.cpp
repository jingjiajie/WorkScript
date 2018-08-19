#include "EqualExpression.h"
#include "TypeExpression.h"
#include "BooleanExpression.h"
#include "Program.h"
#include "StringExpression.h"

using namespace std;

EqualExpression::~EqualExpression()
{
}

TypeExpression* const EqualExpression::getType(Context *const& context) const
{
	return &TypeExpression::EQUAL_EXPRESSION;
}

StringExpression *const EqualExpression::toString(Context *const& context)
{
	static StringExpression equal("==");
	return BinaryTermExpression::toString(context, &equal);
}

Expression* const EqualExpression::evaluate(Context *const &context)
{
	auto left = this->leftExpression->evaluate(context);
	auto right = this->rightExpression->evaluate(context);
	bool eq = left->equals(context, right);
	auto ret = BooleanExpression::newInstance(eq);
	left->releaseTemp();
	right->releaseTemp();
	return ret;
}