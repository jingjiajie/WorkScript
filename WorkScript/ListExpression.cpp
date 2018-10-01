#include "stdafx.h"
#include "ListExpression.h"
#include "TypeExpression.h"
#include "Program.h"
#include "StringExpression.h"

using namespace std;

ListExpression::~ListExpression()
{
	delete []this->items;
}


const Pointer<TypeExpression> ListExpression::getType(Context *const& context) const
{
	return TypeExpression::LIST_EXPRESSION;
}

const Pointer<StringExpression> ListExpression::toString(Context *const& context)
{
	static Pointer<StringExpression> leftBracket(new StringExpression(L"[", ReleaseStrategy::DELETE));
	static Pointer<StringExpression> rightBracket(new StringExpression(L"]", ReleaseStrategy::DELETE));
	static Pointer<StringExpression> comma(new StringExpression(L", ", ReleaseStrategy::DELETE));
	size_t itemCount = this->count;
	size_t strCount = itemCount == 0 ? 2 : itemCount * 2 + 1;
	Pointer<StringExpression>*strExprs = new Pointer<StringExpression>[strCount];
	strExprs[0] = leftBracket;
	strExprs[strCount - 1] = rightBracket;
	for (size_t itemPos = 0, strPos = 1; itemPos < itemCount; itemPos++, strPos += 2) {
		strExprs[strPos] = this->items[itemPos]->toString(context);
		//如果不是最后一项，则添加逗号
		if (itemPos != itemCount - 1) strExprs[strPos + 1] = comma;
	}
	auto result = StringExpression::combine(strExprs, strCount);
	delete[]strExprs;
	return result;
}

void ListExpression::link(LinkContext *const &context)
{
	for (size_t i = 0; i < count; ++i) {
		this->items[i]->link(context);
	}
}

const Pointer<Expression> ListExpression::evaluate(Context *const& context)
{
		Pointer<Expression>*evaluatedItems = new Pointer<Expression>[this->count];
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

bool ListExpression::equals(Context *const &context, const Pointer<Expression> &target) const
{
	if (!target->getType(context)->equals(context, this->getType(context))) {
		return false;
	}
	auto targetListExpr = (const Pointer<ListExpression> &)(target);
	if (this->count != targetListExpr->count) return false;
	for (size_t i = 0; i < this->count; ++i) {
		if (!this->items[i]->equals(context, targetListExpr->items[i]))return false;
	}
	return true;
}
