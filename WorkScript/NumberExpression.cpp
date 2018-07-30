#include "NumberExpression.h"
#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "PolynomialExpression.h"
#include "IdentifierExpression.h"
#include "RelationExpression.h"
#include "ParentheseExpression.h"

using namespace std;

NumberExpression::NumberExpression(Context *const &context)
	:TermExpression(context)
{

}

NumberExpression::NumberExpression(Context * const & context, const double & value)
	:NumberExpression(context)
{
	this->setValue(value);
}


NumberExpression::~NumberExpression()
{
}

const std::shared_ptr<const Expression> NumberExpression::evaluate(const ExpressionBind &) const
{
	//auto matchResult = this->matchFirstUpInContextAndEvaluate(this->shared_from_this());
	//return matchResult == nullptr ? this->shared_from_this() : matchResult;
	return this->shared_from_this();
}

bool NumberExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	return this->equals(matchExpression);
}

bool NumberExpression::equals(const std::shared_ptr<const Expression>&matchExpression) const
{
	//如果类型不同，匹配失败
	if (!matchExpression->getType()->equals(this->getType())) {
		return false;
	}
	//类型相同，比较值是否相同
	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
	return matchValueExpression->getValue() == this->getValue();
}

const std::shared_ptr<const TypeExpression> NumberExpression::getType() const
{
	return this->context->findType(TYPENAME_NUMBER_EXPRESSION, false);
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

const double NumberExpression::getValue() const
{
	return this->value;
}

void NumberExpression::setValue(const double &value)
{
	this->value = value;
}
