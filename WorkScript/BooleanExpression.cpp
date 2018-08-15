#include "BooleanExpression.h"
#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include <type_traits>

using namespace std;

shared_ptr<BooleanExpression> BooleanExpression::YES(new BooleanExpression(true));
shared_ptr<BooleanExpression> BooleanExpression::NO(new BooleanExpression(false));

BooleanExpression::BooleanExpression()
	:TermExpression()
{

}

BooleanExpression::BooleanExpression(const bool & value)
	: BooleanExpression()
{
	this->setValue(value);
}


BooleanExpression::~BooleanExpression()
{
}

const std::shared_ptr<TermExpression> BooleanExpression::evaluate(Context *context)
{
	return (const std::shared_ptr<TermExpression>&)this->shared_from_this();
}

//bool BooleanExpression::match(const std::shared_ptr<TermExpression>& matchExpression, Context * context) const
//{
//	//如果类型不同，匹配失败
//	if (!matchExpression->getType()->equals(this->getType())) {
//		return false;
//	}
//	//类型相同，比较值是否相同
//	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
//	return matchValueExpression->getValue() == this->getValue();
//}

const std::shared_ptr<TypeExpression> BooleanExpression::getType() const
{
	return TypeExpression::BOOLEAN_EXPRESSION;
}

bool BooleanExpression::equals(const std::shared_ptr<TermExpression>& targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType())) {
		return false;
	}
	auto targetExpressionOfMyType = dynamic_pointer_cast<remove_pointer_t<decltype(this)>>(targetExpression);
	
	return targetExpressionOfMyType->getValue() == this->value;
}

const std::string BooleanExpression::toString() const
{
	if (this->value)return "true";
	else return "false";
}

void BooleanExpression::compile(CompileContext * context)
{
	return;
}

const bool BooleanExpression::getValue() const
{
	return this->value;
}

void BooleanExpression::setValue(const bool &value)
{
	this->value = value;
}
