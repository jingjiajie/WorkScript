#include "ParameterExpression.h"
#include "TypeExpression.h"
#include "StringExpression.h"
#include "AssignmentExpression.h"

ParameterExpression::~ParameterExpression()
{
	if (this->items) delete[]this->items;
}

const Pointer<TypeExpression> ParameterExpression::getType(Context * const & context) const
{
	return TypeExpression::PARAMETER_EXPRESSION;
}

const Pointer<StringExpression> ParameterExpression::toString(Context * const & context)
{
	static Pointer<StringExpression> comma = new StringExpression(L",", ReleaseStrategy::DELETE);
	size_t itemCount = this->count;
	//�����0�ֱ�ӷ��ؿ��ַ���������
	if (itemCount == 0) {
		return StringExpression::newInstance(L"");
	}
	//���򷵻ض��ŷָ��ĸ���
	size_t strCount = itemCount * 2 - 1;
	Pointer<StringExpression>*strExprs = new Pointer<StringExpression>[strCount];
	for (size_t itemPos = 0, strPos = 0; itemPos < itemCount; ++itemPos, strPos += 2) {
		strExprs[strPos] = this->items[itemPos]->toString(context);
		//����������һ�����Ӷ���
		if (itemPos != itemCount - 1) strExprs[strPos + 1] = comma;
	}
	auto result = StringExpression::combine(strExprs, strCount);
	delete[]strExprs;
	return result;
}

void ParameterExpression::compile(CompileContext * const & context)
{
	for (size_t i = 0; i < count; ++i) {
		this->items[i]->compile(context);
	}
}

const Pointer<Expression> ParameterExpression::evaluate(Context * const & context)
{
	//�ڲ������ʽ�����������ֵ��䣬��������ĸ�ֵ������ֱ�ӷ��ظ�ֵ��䡣
	Pointer<Expression> *evaluatedItems = new Pointer<Expression>[this->count];
	for (size_t i = 0; i < this->count; ++i) {
		if (this->items[i]->getType(context)->equals(context, TypeExpression::ASSIGNMENT_EXPRESSION)) {
			evaluatedItems[i] = ((Pointer<AssignmentExpression>)this->items[i])->evaluateParamAssignment(context);
		}
		else {
			evaluatedItems[i] = this->items[i]->evaluate(context);
		}
	}
	auto newMe = new ParameterExpression(evaluatedItems, this->count);
	return newMe;
}

bool ParameterExpression::equals(Context * const & context, const Pointer<Expression> &target) const
{
	if (!target->getType(context)->equals(context, this->getType(context))) {
		return false;
	}
	auto targetListExpr = (const Pointer<ParameterExpression>)(target);
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
		if (!this->items[i]->getType(context)->equals(context, TypeExpression::PARAMETER_EXPRESSION))continue;
		flatLength += ((Pointer<ParameterExpression>)this->items[i])->getCount() - 1;
	}
	//��������б����������б�����չƽ��ֱ�ӷ���
	if (flatLength == this->count)return;
	auto oldItems = this->items;
	size_t oldCount = this->count;
	this->count = flatLength;
	this->items = new Pointer<Expression>[flatLength];
	size_t newPos = 0;
	for (size_t oldPos = 0; oldPos < oldCount; ++oldPos) {
		auto curOldItem = oldItems[oldPos];
		if (!curOldItem->getType(context)->equals(context, TypeExpression::PARAMETER_EXPRESSION)) {
			this->items[newPos++] = curOldItem;
		}
		else {
			for (size_t curOldItemPos = 0; curOldItemPos < ((Pointer<ParameterExpression>)curOldItem)->getCount(); ++curOldItemPos)
			{
				this->items[newPos++] = ((Pointer<ParameterExpression>)curOldItem)->items[curOldItemPos];
			}
		}
	}
	delete[]oldItems;
}
