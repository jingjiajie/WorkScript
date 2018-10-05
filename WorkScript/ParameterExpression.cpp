#include "stdafx.h"
#include "ParameterExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "AssignmentExpression.h"

using namespace WorkScript;
using namespace std;

ParameterExpression::~ParameterExpression()
{
	for (Expression *expr : this->items)
	{
		delete expr;
	}
}

Type * ParameterExpression::getType() const
{
	return nullptr;
}

std::wstring ParameterExpression::toString()
{
	size_t itemCount = this->count;
	//如果有0项，直接返回空字符串就行了
	if (itemCount == 0) {
		return L"";
	}
	wstringstream ss;
	//否则返回逗号分隔的各项
	for (size_t i = 0; i < itemCount; ++i)
	{
		ss << this->items[i]->toString();
		if (i != itemCount - 1) ss << L", ";
	}
	return ss.str();
}

//bool ParameterExpression::equals(Context * const & context, Expression *target) const
//{
//	if (!target->getType(context)->equals(context, this->getType(context))) {
//		return false;
//	}
//	auto targetListExpr = (const Pointer<ParameterExpression>)(target);
//	if (this->count != targetListExpr->count) return false;
//	for (size_t i = 0; i < this->count; ++i) {
//		if (!this->items[i]->equals(context, targetListExpr->items[i]))return false;
//	}
//	return true;
//}

void ParameterExpression::flat()
{
	size_t flatLength = this->count;
	for (size_t i = 0; i < this->count; ++i)
	{
		if (this->items[i]->getExpressionType() != ExpressionType::PARAMETER_EXPRESSION)continue;
		flatLength += ((ParameterExpression*)this->items[i])->getCount() - 1;
	}
	//如果参数列表不包含参数列表，则不用展平，直接返回
	if (flatLength == this->count)return;
	auto oldItems = this->items;
	size_t oldCount = this->count;
	this->count = flatLength;
	this->items.reserve(this->count);
	size_t newPos = 0;
	for (size_t oldPos = 0; oldPos < oldCount; ++oldPos) {
		auto curOldItem = oldItems[oldPos];
		if (curOldItem->getExpressionType() != ExpressionType::PARAMETER_EXPRESSION) {
			this->items[newPos++] = curOldItem;
		}
		else {
			for (size_t curOldItemPos = 0; curOldItemPos < ((ParameterExpression*)curOldItem)->getCount(); ++curOldItemPos)
			{
				this->items[newPos++] = ((ParameterExpression*)curOldItem)->items[curOldItemPos];
			}
		}
	}
}
