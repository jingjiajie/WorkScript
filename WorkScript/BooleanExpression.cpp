#include "BooleanExpression.h"
#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "Program.h"
#include "IllegalValueException.h"

using namespace std;

ObjectPool<BooleanExpression> BooleanExpression::pool(1024);

BooleanExpression BooleanExpression::VAL_FALSE(0, StorageLevel::EXTERN);
BooleanExpression BooleanExpression::VAL_TRUE(1, StorageLevel::EXTERN);
BooleanExpression BooleanExpression::VAL_NO(2, StorageLevel::EXTERN);
BooleanExpression BooleanExpression::VAL_YES(3, StorageLevel::EXTERN);

StringExpression BooleanExpression::STR_FALSE("false", StorageLevel::EXTERN);
StringExpression BooleanExpression::STR_TRUE("true", StorageLevel::EXTERN);
StringExpression BooleanExpression::STR_NO("no", StorageLevel::EXTERN);
StringExpression BooleanExpression::STR_YES("yes", StorageLevel::EXTERN);

BooleanExpression::~BooleanExpression()
{
}

Expression* const BooleanExpression::evaluate(Context *const& context)
{
	return this->storageLevel == StorageLevel::LITERAL ? BooleanExpression::newInstance(this->value) : this;
}

//bool BooleanExpression::match(Expression* const& matchExpression,Context *const &context) const
//{
//	//如果类型不同，匹配失败
//	if (!matchExpression->getType(context)->equals(this->getType(context))) {
//		return false;
//	}
//	//类型相同，比较值是否相同
//	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
//	return matchValueExpression->getValue() == this->getValue();
//}

bool BooleanExpression::equals(Context *const &context, Expression* const& targetExpression) const
{
	if (targetExpression == this)return true;
	if (!targetExpression->getType(context)->equals(context, this->getType(context))) {
		return false;
	}
	auto targetExpressionOfMyType = (BooleanExpression *const&)targetExpression;
	//偶数为假，奇数为真
	return targetExpressionOfMyType->value % 2 == this->value % 2;
}

StringExpression * const BooleanExpression::toString(Context * const & context)
{
	switch (this->value) {
	case 0:return &BooleanExpression::STR_FALSE;
	case 1:return &BooleanExpression::STR_TRUE;
	case 2:return &BooleanExpression::STR_NO;
	case 3:return &BooleanExpression::STR_YES;
	default:
		throw IllegalValueException((to_string(this->value) + "不是合法的布尔值！").c_str());
	}
}