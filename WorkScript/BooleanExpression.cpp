#include "BooleanExpression.h"
#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "Program.h"
#include "IllegalValueException.h"
#include <boost/locale.hpp>
using namespace std;

OBJECT_POOL_MEMBER_IMPL(BooleanExpression, 64);

//真值
Pointer<BooleanExpression> BooleanExpression::VAL_TRUE(new BooleanExpression(1, ReleaseStrategy::DELETE));
Pointer<BooleanExpression> BooleanExpression::VAL_YES(new BooleanExpression(3, ReleaseStrategy::DELETE));
Pointer<BooleanExpression> BooleanExpression::VAL_OK(new BooleanExpression(5, ReleaseStrategy::DELETE));
Pointer<BooleanExpression> BooleanExpression::VAL_GOOD(new BooleanExpression(7, ReleaseStrategy::DELETE));

Pointer<StringExpression> BooleanExpression::STR_TRUE(new StringExpression(L"true", ReleaseStrategy::DELETE));
Pointer<StringExpression> BooleanExpression::STR_YES(new StringExpression(L"yes", ReleaseStrategy::DELETE));
Pointer<StringExpression> BooleanExpression::STR_OK(new StringExpression(L"ok", ReleaseStrategy::DELETE));
Pointer<StringExpression> BooleanExpression::STR_GOOD(new StringExpression(L"good", ReleaseStrategy::DELETE));

//假值
Pointer<BooleanExpression> BooleanExpression::VAL_FALSE(new BooleanExpression(0, ReleaseStrategy::DELETE));
Pointer<BooleanExpression> BooleanExpression::VAL_NO(new BooleanExpression(2, ReleaseStrategy::DELETE));
Pointer<BooleanExpression> BooleanExpression::VAL_BAD(new BooleanExpression(4, ReleaseStrategy::DELETE));

Pointer<StringExpression> BooleanExpression::STR_FALSE(new StringExpression(L"false", ReleaseStrategy::DELETE));
Pointer<StringExpression> BooleanExpression::STR_NO(new StringExpression(L"no", ReleaseStrategy::DELETE));
Pointer<StringExpression> BooleanExpression::STR_BAD(new StringExpression(L"bad", ReleaseStrategy::DELETE));


BooleanExpression::~BooleanExpression()
{
}

const Pointer<Expression> BooleanExpression::evaluate(Context *const& context)
{
	return this;
}

//bool BooleanExpression::match(const Pointer<Expression> & matchExpression,Context *const &context) const
//{
//	//如果类型不同，匹配失败
//	if (!matchExpression->getType(context)->equals(this->getType(context))) {
//		return false;
//	}
//	//类型相同，比较值是否相同
//	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
//	return matchValueExpression->getValue() == this->getValue();
//}

bool BooleanExpression::equals(Context *const &context, const Pointer<Expression> & targetExpression) const
{
	if (targetExpression == this)return true;
	if (!targetExpression->getType(context)->equals(context, this->getType(context))) {
		return false;
	}
	auto targetExpressionOfMyType = (const Pointer<BooleanExpression> &)targetExpression;
	//偶数为假，奇数为真
	return targetExpressionOfMyType->value % 2 == this->value % 2;
}

const Pointer<StringExpression> BooleanExpression::toString(Context * const & context)
{
	switch (this->value) {
	case 1:return BooleanExpression::STR_TRUE;
	case 3:return BooleanExpression::STR_YES;
	case 5:return BooleanExpression::STR_OK;
	case 7:return BooleanExpression::STR_GOOD;

	case 0:return BooleanExpression::STR_FALSE;
	case 2:return BooleanExpression::STR_NO;
	case 4:return BooleanExpression::STR_BAD;
	default:
		throw IllegalValueException((to_wstring(this->value) + L"不是合法的布尔值！").c_str());
	}
}