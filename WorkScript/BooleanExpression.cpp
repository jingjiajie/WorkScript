#include "BooleanExpression.h"
#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "Program.h"

using namespace std;

ObjectPool<BooleanExpression> BooleanExpression::pool(1024);

BooleanExpression BooleanExpression::YES(true, StorageLevel::EXTERN);
BooleanExpression BooleanExpression::NO(false, StorageLevel::EXTERN);

StringExpression BooleanExpression::STR_YES("yes", StorageLevel::EXTERN);
StringExpression BooleanExpression::STR_NO("no", StorageLevel::EXTERN);

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
	
	return targetExpressionOfMyType->getValue() == this->value;
}

StringExpression * const BooleanExpression::toString(Context * const & context)
{
	return this->value ? &BooleanExpression::STR_YES : &BooleanExpression::STR_NO;
}