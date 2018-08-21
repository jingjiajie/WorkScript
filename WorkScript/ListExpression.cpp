#include <sstream>
#include "ListExpression.h"
#include "TypeExpression.h"
#include "Program.h"
#include "StringExpression.h"

using namespace std;

ListExpression::~ListExpression()
{
	for (size_t i = 0; i < this->count; ++i) {
		this->items[i]->release(this->storageLevel);
	}
}


TypeExpression* const ListExpression::getType(Context *const& context) const
{
	return &TypeExpression::LIST_EXPRESSION;
}

StringExpression *const ListExpression::toString(Context *const& context)
{
	static StringExpression leftBracket("[", StorageLevel::EXTERN),rightBracket("]", StorageLevel::EXTERN),comma(", ", StorageLevel::EXTERN);
	size_t itemCount = this->count;
	size_t strCount = itemCount == 0 ? 2 : itemCount * 2 + 1;
	StringExpression **strExprs = new StringExpression*[strCount];
	strExprs[0] = &leftBracket;
	strExprs[strCount - 1] = &rightBracket;
	for (size_t itemPos = 0, strPos = 1; itemPos < itemCount; itemPos++, strPos += 2) {
		strExprs[strPos] = this->items[itemPos]->toString(context);
		//如果不是最后一项，则添加逗号
		if (itemPos != itemCount - 1) strExprs[strPos + 1] = &comma;
	}
	auto result = StringExpression::combine(strExprs, strCount);
	for (size_t i = 0; i < itemCount; ++i) {
		strExprs[i * 2 + 1]->releaseTemp();
	}
	delete[]strExprs;
	return result;
}

void ListExpression::compile(CompileContext *const &context)
{
	for (size_t i = 0; i < count; ++i) {
		this->items[i]->compile(context);
	}
}

Expression* const ListExpression::evaluate(Context *const& context)
{
	if (this->getStorageLevel() == StorageLevel::LITERAL) 
	{
		Expression **evaluatedItems = new Expression *[this->count];
		for (size_t i = 0; i < this->count; ++i) {
			evaluatedItems[i] = this->items[i]->evaluate(context);
		}
		auto newMe = new ListExpression();
		for (size_t i = 0; i < this->count; ++i) {
			newMe->addItem(evaluatedItems[i]);
		}
		delete[]evaluatedItems;
		return newMe;
	}
	else {
		return this;
	}
}

bool ListExpression::equals(Context *const &context, Expression *const &target) const
{
	if (!target->getType(context)->equals(context, this->getType(context))) {
		return false;
	}
	auto targetListExpr = (ListExpression *const&)(target);
	if (this->count != targetListExpr->count) return false;
	for (size_t i = 0; i < this->count; ++i) {
		if (!this->items[i]->equals(context, targetListExpr->items[i]))return false;
	}
	return true;
}
