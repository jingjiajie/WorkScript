#include <type_traits>
#include "BinaryTermExpression.h"
#include "TypeExpression.h"

using namespace std;

BinaryTermExpression::BinaryTermExpression()
{
}


BinaryTermExpression::~BinaryTermExpression()
{
}

bool BinaryTermExpression::equals(const shared_ptr<TermExpression> &targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType())) {
		return false;
	}
	auto targetExpressionOfMyType = dynamic_pointer_cast<remove_pointer_t<decltype(this)>>(targetExpression);

	return this->leftExpression->equals(targetExpressionOfMyType->leftExpression) && this->rightExpression->equals(targetExpressionOfMyType->rightExpression);
}

void BinaryTermExpression::compile(CompileContext * context)
{
	this->leftExpression->compile(context);
	this->rightExpression->compile(context);
}


const std::shared_ptr<TermExpression> BinaryTermExpression::getLeftExpression() const
{
	return this->leftExpression;
}

void BinaryTermExpression::setLeftExpression(const std::shared_ptr<TermExpression> &expr)
{
	this->leftExpression = expr;
}

const std::shared_ptr<TermExpression> BinaryTermExpression::getRightExpression() const
{
	return this->rightExpression;
}

void BinaryTermExpression::setRightExpression(const std::shared_ptr<TermExpression> &expr)
{
	this->rightExpression = expr;
}