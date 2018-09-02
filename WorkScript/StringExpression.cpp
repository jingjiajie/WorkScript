#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "Program.h"
#include <string.h>

using namespace std;

OBJECT_POOL_MEMBER_IMPL(StringExpression,64);

const Pointer<StringExpression> StringExpression::combine(const Pointer<StringExpression> *const &stringExpressions, const size_t &count)
{
	auto newInstance = OBJECT_POOL_GET;
	size_t totalLength = 0;
	for (size_t i = 0; i < count; ++i) {
		totalLength += stringExpressions[i]->getLength();
	}

	wchar_t *buff = new wchar_t[totalLength + 1];
	for (size_t i = 0, curPos = 0; i < count; curPos += stringExpressions[i]->getLength(), ++i) {
		wcscpy(buff + curPos, stringExpressions[i]->getValue());
	}
	if (newInstance->value)delete[]newInstance->value;
	newInstance->value = buff;
	newInstance->length = totalLength;
	return newInstance;
}

void StringExpression::release()
{
	OBJECT_POOL_PUSH(this);
	//printf("push string %p\n", this);
}

//
//bool StringExpression::match(const Pointer<Expression> & matchExpression, Context *const& context) const
//{
//	//如果类型不同，匹配失败
//	if (!matchExpression->getType(context)->equals(this->getType(context))) {
//		return false;
//	}
//	//类型相同，比较值是否相同
//	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
//	return matchValueExpression->getValue() == this->getValue();
//}
