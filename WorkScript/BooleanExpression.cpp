#include "BooleanExpression.h"
#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "PolynomialExpression.h"
#include "IdentifierExpression.h"
#include "RelationExpression.h"
#include "ParentheseExpression.h"

using namespace std;

BooleanExpression::BooleanExpression(Context *const &context)
	:TermExpression(context)
{
	this->type = this->context->findType(TYPENAME_BOOLEAN_EXPRESSION, false);
}

BooleanExpression::BooleanExpression(Context * const & context, const bool & value)
	: BooleanExpression(context)
{
	this->setValue(value);
}


BooleanExpression::~BooleanExpression()
{
}

const std::shared_ptr<const Expression> BooleanExpression::evaluate(const ExpressionBind &) const
{
	//auto matchResult = this->matchFirstUpInContextAndEvaluate(this->shared_from_this());
	//return matchResult == nullptr ? this->shared_from_this() : matchResult;
	return this->shared_from_this();
}

bool BooleanExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	return this->equals(matchExpression);
}

bool BooleanExpression::equals(const std::shared_ptr<const Expression>&matchExpression) const
{
	//如果类型不同，匹配失败
	if (!matchExpression->getType()->equals(this->getType())) {
		return false;
	}
	//类型相同，比较值是否相同
	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
	return matchValueExpression->getValue() == this->getValue();
}

const std::shared_ptr<const TypeExpression> BooleanExpression::getType() const
{
	return this->type;
}

const std::string BooleanExpression::toString() const
{
	if (this->value)return "true";
	else return "false";
}

const bool BooleanExpression::getValue() const
{
	return this->value;
}

void BooleanExpression::setValue(const bool &value)
{
	this->value = value;
}
