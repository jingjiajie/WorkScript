#include "StringExpression.h"
#include "TypeExpression.h"
#include "Context.h"
#include "Program.h"
#include <string.h>

using namespace std;

ObjectPool<StringExpression> StringExpression::pool(1024);

StringExpression *const StringExpression::combine(const StringExpression *const *const &stringExpressions, const size_t &count, const StorageLevel level)
{
	auto newInstance = StringExpression::pool.get();
	newInstance->setStorageLevel(level);
	size_t totalLength = 0;
	for (size_t i = 0; i < count; ++i) {
		totalLength += stringExpressions[i]->getLength();
	}

	char *buff = new char[totalLength + 1];
	for (size_t i = 0, curPos = 0; i < count; curPos += stringExpressions[i]->getLength(), ++i) {
		strcpy(buff + curPos, stringExpressions[i]->getValue());
	}
	if (newInstance->value)delete[]newInstance->value;
	newInstance->value = buff;
	newInstance->length = totalLength;
	return newInstance;
}

void StringExpression::release()
{
	StringExpression::pool.push(this);
	//printf("push string %p\n", this);
}

//
//bool StringExpression::match(Expression* const& matchExpression, Context *const& context) const
//{
//	//如果类型不同，匹配失败
//	if (!matchExpression->getType(context)->equals(this->getType(context))) {
//		return false;
//	}
//	//类型相同，比较值是否相同
//	auto matchValueExpression = (const std::shared_ptr<std::remove_pointer<decltype(this)>::type> &)matchExpression;
//	return matchValueExpression->getValue() == this->getValue();
//}
