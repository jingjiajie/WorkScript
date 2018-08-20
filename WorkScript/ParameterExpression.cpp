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
	static StringExpression comma(", ");
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
	for (size_t i = 0; i < strCount; i++) {
		strExprs[i]->releaseTemp();
	}
	delete[]strExprs;
	return result;
}

void ParameterExpression::compile(CompileContext * const & context)
{
	for (size_t i = 0; i < count; i++) {
		this->items[i]->compile(context);
	}
}

Expression * const ParameterExpression::evaluate(Context * const & context)
{
	if (this->getStorageLevel() == StorageLevel::LITERAL)
	{
		Expression **evaluatedItems = new Expression *[this->count];
		for (size_t i = 0; i < this->count; i++) {
			evaluatedItems[i] = this->items[i]->evaluate(context);
		}
		auto newMe = new ParameterExpression(this->count);
		for (size_t i = 0; i < this->count; i++) {
			newMe->setItem(i,evaluatedItems[i]);
		}
		delete[]evaluatedItems;
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
	for (size_t i = 0; i < this->count; i++) {
		if (!this->items[i]->equals(context, targetListExpr->items[i]))return false;
	}
	return true;
}
