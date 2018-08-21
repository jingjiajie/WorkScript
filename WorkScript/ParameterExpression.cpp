#include "ParameterExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"

ParameterExpression::~ParameterExpression()
{
	for (size_t i = 0; i < count; ++i)
	{
		this->items[i]->release(this->storageLevel);
	}
}

TypeExpression * const ParameterExpression::getType(Context * const & context) const
{
	return &TypeExpression::PARAMETER_EXPRESSION;
}

StringExpression * const ParameterExpression::toString(Context * const & context)
{
	static StringExpression comma(",",StorageLevel::EXTERN);
	size_t itemCount = this->count;
	//如果有0项，直接返回空字符串就行了
	if (itemCount == 0) {
		return StringExpression::newInstance("");
	}
	//否则返回逗号分隔的各项
	size_t strCount = itemCount * 2 - 1;
	StringExpression **strExprs = new StringExpression*[strCount];
	for (size_t itemPos = 0, strPos = 0; itemPos < itemCount; ++itemPos, strPos += 2) {
		strExprs[strPos] = this->items[itemPos]->toString(context);
		//如果不是最后一项，则添加逗号
		if (itemPos != itemCount - 1) strExprs[strPos + 1] = &comma;
	}
	auto result = StringExpression::combine(strExprs, strCount);
	for (size_t i = 0; i < strCount; ++i) {
		strExprs[i]->releaseTemp();
	}
	delete[]strExprs;
	return result;
}

void ParameterExpression::compile(CompileContext * const & context)
{
	for (size_t i = 0; i < count; ++i) {
		this->items[i]->compile(context);
	}
}

Expression * const ParameterExpression::evaluate(Context * const & context)
{
	if (this->getStorageLevel() == StorageLevel::LITERAL)
	{
		Expression **evaluatedItems = new Expression *[this->count];
		for (size_t i = 0; i < this->count; ++i) {
			evaluatedItems[i] = this->items[i]->evaluate(context);
		}
		auto newMe = new ParameterExpression(evaluatedItems, this->count);
		return newMe;
	}
	else {
		return this;
	}
}

bool ParameterExpression::equals(Context * const & context, Expression * const &target) const
{
	if (!target->getType(context)->equals(context, this->getType(context))) {
		return false;
	}
	auto targetListExpr = (ParameterExpression *const&)(target);
	if (this->count != targetListExpr->count) return false;
	for (size_t i = 0; i < this->count; ++i) {
		if (!this->items[i]->equals(context, targetListExpr->items[i]))return false;
	}
	return true;
}

void ParameterExpression::flat(Context *const &context)
{
	size_t flatLength = this->count;
	for (size_t i = 0; i < this->count; ++i)
	{
		if (!this->items[i]->getType(context)->equals(context, &TypeExpression::PARAMETER_EXPRESSION))continue;
		flatLength += ((ParameterExpression*)this->items[i])->getCount() - 1;
	}
	//如果参数列表不包含参数列表，则不用展平，直接返回
	if (flatLength == this->count)return;
	auto oldItems = this->items;
	size_t oldCount = this->count;
	this->count = flatLength;
	this->items = new Expression*[flatLength];
	size_t newPos = 0;
	for (size_t oldPos = 0; oldPos < oldCount; ++oldPos) {
		auto curOldItem = oldItems[oldPos];
		if (!curOldItem->getType(context)->equals(context, &TypeExpression::PARAMETER_EXPRESSION)) {
			this->items[newPos++] = curOldItem;
		}
		else {
			for (size_t curOldItemPos = 0; curOldItemPos < ((ParameterExpression*)curOldItem)->getCount(); ++curOldItemPos)
			{
				this->items[newPos++] = ((ParameterExpression*)curOldItem)->items[curOldItemPos];
			}
		}
	}
	delete[]oldItems;
}
