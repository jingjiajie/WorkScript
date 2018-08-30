#include "NumberExpression.h"
#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "Program.h"

using namespace std;

ObjectPool<NumberExpression> NumberExpression::pool(1024);

NumberExpression::~NumberExpression()
{
}

Expression* const NumberExpression::evaluate(Context *const& context)
{
	return this->storageLevel == StorageLevel::LITERAL ? NumberExpression::newInstance(this->value) : this;
}

//bool NumberExpression::match(Expression* const& matchExpression, Context *const& context) const
//{
//	//如果类型不同，匹配失败
//	if (!matchExpression->getType(context)->equals(this->getType(context))) {
//		return false;
//	}
//	//类型相同，比较值是否相同
//	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
//	return matchValueExpression->getValue() == this->getValue();
//}

bool NumberExpression::equals(Context *const &context, Expression* const& targetExpression) const
{
	if (targetExpression == this)return true;
	if (!targetExpression->getType(context)->equals(context, this->getType(context)))return false;
	return ((NumberExpression *const&)targetExpression)->getValue() == this->getValue();
}

StringExpression *const NumberExpression::toString(Context *const& context)
{
	double number = this->value;
	wstring numberStr;
	if (fabs(number - (int)number) < 1e-8) {
		numberStr = to_wstring((int)number);
	}
	else { //如果是小数，删除末尾0
		numberStr = to_wstring(number);
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
	return StringExpression::newInstance(numberStr.c_str());
}

void NumberExpression::compile(CompileContext *const &context)
{
	return;
}