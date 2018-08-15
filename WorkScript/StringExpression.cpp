#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"

using namespace std;

StringExpression::StringExpression()
{

}

StringExpression::StringExpression(const std::string & value)
{
	this->setValue(value);
}


StringExpression::~StringExpression()
{
}

const std::shared_ptr<TermExpression> StringExpression::evaluate(Context *context)
{
	return (const std::shared_ptr<TermExpression>&)this->shared_from_this();
}
//
//bool StringExpression::match(const std::shared_ptr<TermExpression>& matchExpression, Context *context) const
//{
//	//如果类型不同，匹配失败
//	if (!matchExpression->getType()->equals(this->getType())) {
//		return false;
//	}
//	//类型相同，比较值是否相同
//	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
//	return matchValueExpression->getValue() == this->getValue();
//}

const std::shared_ptr<TypeExpression> StringExpression::getType() const
{
	return TypeExpression::STRING_EXPRESSION;
}

bool StringExpression::equals(const std::shared_ptr<TermExpression>& targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType())) {
		return false;
	}
	return dynamic_pointer_cast<StringExpression>(targetExpression)->getValue() == this->value;
}

const std::string StringExpression::toString() const
{
	return this->value;
}

void StringExpression::compile(CompileContext * context)
{
	return;
}

const std::string StringExpression::getValue() const
{
	return this->value;
}

void StringExpression::setValue(const std::string & value)
{
	this->value = value;
}
