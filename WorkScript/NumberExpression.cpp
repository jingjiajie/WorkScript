#include "NumberExpression.h"
#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"

using namespace std;

NumberExpression::NumberExpression()
{

}

NumberExpression::NumberExpression(const double & value)
{
	this->setValue(value);
}


NumberExpression::~NumberExpression()
{
}

const std::shared_ptr<TermExpression> NumberExpression::evaluate(Context *context)
{
	return (const std::shared_ptr<TermExpression>&)this->shared_from_this();
}

//bool NumberExpression::match(const std::shared_ptr<TermExpression>& matchExpression, Context *context) const
//{
//	//如果类型不同，匹配失败
//	if (!matchExpression->getType()->equals(this->getType())) {
//		return false;
//	}
//	//类型相同，比较值是否相同
//	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
//	return matchValueExpression->getValue() == this->getValue();
//}

const std::shared_ptr<TypeExpression> NumberExpression::getType() const
{
	return TypeExpression::NUMBER_EXPRESSION;
}

bool NumberExpression::equals(const std::shared_ptr<TermExpression>& targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType()))return false;
	auto targetNumExpr = dynamic_pointer_cast<NumberExpression>(targetExpression);
	return targetNumExpr->getValue() == this->getValue();
}

const std::string NumberExpression::toString() const
{
	double number = this->value;
	string numberStr;
	if (fabs(number - (int)number) < 1e-8) {
		numberStr = to_string((int)number);
	}
	else { //如果是小数，删除末尾0
		numberStr = to_string(number);
		size_t lastZeroCount = 0;
		for (size_t i = numberStr.size() - 1; i >= 0; i--) {
			if (numberStr[i] == '0') {
				lastZeroCount++;
			}
			else {
				break;
			}
		}
		numberStr = numberStr.substr(0, numberStr.size() - lastZeroCount);
	}
	return numberStr;
}

void NumberExpression::compile(CompileContext * context)
{
	return;
}

const double NumberExpression::getValue() const
{
	return this->value;
}

void NumberExpression::setValue(const double &value)
{
	this->value = value;
}
