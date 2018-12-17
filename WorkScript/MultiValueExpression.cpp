#include "stdafx.h"
#include "MultiValueExpression.h"
#include "Type.h"
#include "StringExpression.h"
#include "AssignmentExpression.h"
#include "Utils.h"

using namespace WorkScript;
using namespace std;

MultiValueExpression::~MultiValueExpression()
{
	for (Expression *expr : this->items)
	{
		delete expr;
	}
}

Type * MultiValueExpression::getType() const
{
	return nullptr;
}

std::vector<Type*> WorkScript::MultiValueExpression::getTypes() const
{
	vector<Type*> paramTypes;
	paramTypes.reserve(items.size());
	for (size_t i = 0; i<items.size(); ++i)
	{
		paramTypes[i] = this->items[i]->getType();
	}
	return paramTypes;
}

std::wstring MultiValueExpression::toString() const
{
	size_t itemCount = this->items.size();
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

Expression * WorkScript::MultiValueExpression::clone() const
{
	vector<Expression*> newItems;
	newItems.reserve(this->items.size());
	for (size_t i = 0; i < this->items.size(); ++i)
	{
		newItems[i] = this->items[i]->clone();
	}
	auto newInstance = new thistype(EXPRESSION_MEMBERS, newItems);
	return newInstance;
}

Expression * WorkScript::MultiValueExpression::instantialize()
{
	vector<Expression*> newItems;
	for (Expression *expr : this->items)
	{
		newItems.push_back(expr->instantialize());
	}
	return new MultiValueExpression(program, location, newItems);
}

ExpressionType WorkScript::MultiValueExpression::getExpressionType() const
{
	return ExpressionType::PARAMETER_EXPRESSION;
}

GenerateResult WorkScript::MultiValueExpression::generateIR(GenerateContext * context)
{
	throw "请调用getLLVMArgs()";
}

std::vector<llvm::Value*> WorkScript::MultiValueExpression::getLLVMArgs(GenerateContext * context) const
{
	vector<llvm::Value*> args;
	args.reserve(this->items.size());
	for (size_t i = 0; i < this->items.size(); ++i)
	{
		args[i] = this->items[i]->generateIR(context).getValue();
	}
	return args;
}

//bool MultiValueExpression::equals(Context * const & context, Expression *target) const
//{
//	if (!target->getType(context)->equals(context, this->getType(context))) {
//		return false;
//	}
//	auto targetListExpr = (const Pointer<MultiValueExpression>)(target);
//	if (this->count != targetListExpr->count) return false;
//	for (size_t i = 0; i < this->count; ++i) {
//		if (!this->items[i]->equals(context, targetListExpr->items[i]))return false;
//	}
//	return true;
//}
//
//void MultiValueExpression::flat()
//{
//	size_t flatLength = this->count;
//	for (size_t i = 0; i < this->count; ++i)
//	{
//		if (this->items[i]->getExpressionType() != ExpressionType::PARAMETER_EXPRESSION)continue;
//		flatLength += ((MultiValueExpression*)this->items[i])->getCount() - 1;
//	}
//	//如果参数列表不包含参数列表，则不用展平，直接返回
//	if (flatLength == this->count)return;
//	auto oldItems = this->items;
//	size_t oldCount = this->count;
//	this->count = flatLength;
//	this->items.reserve(this->count);
//	size_t newPos = 0;
//	for (size_t oldPos = 0; oldPos < oldCount; ++oldPos) {
//		auto curOldItem = oldItems[oldPos];
//		if (curOldItem->getExpressionType() != ExpressionType::PARAMETER_EXPRESSION) {
//			this->items[newPos++] = curOldItem;
//		}
//		else {
//			for (size_t curOldItemPos = 0; curOldItemPos < ((MultiValueExpression*)curOldItem)->getCount(); ++curOldItemPos)
//			{
//				this->items[newPos++] = ((MultiValueExpression*)curOldItem)->items[curOldItemPos];
//			}
//		}
//	}
//}