#include "GreaterThanExpression.h"
#include "StringExpression.h"
#include "Context.h"
#include "Program.h"

using namespace std;

GreaterThanExpression::~GreaterThanExpression()
{
}

//
//bool GreaterThanExpression::match(const Pointer<Expression> & matchExpression, Context *const& context) const
//{
//	auto evaluatedLeft = this->leftExpression->evaluate(context);
//	auto evaluatedRight = this->rightExpression->evaluate(context);
//	auto numberType = TypeExpression::NUMBER_EXPRESSION;
//	//���ƥ����ڱ��ʽ��������ƥ��
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchGreaterThanExpression = (const Pointer<GreaterThanExpression> &)(matchExpression);
//		return evaluatedLeft->match(matchGreaterThanExpression->leftExpression, context)
//			&& evaluatedRight->match(matchGreaterThanExpression->rightExpression, context);
//	}
//	//����Լ����Ҳ����������ͣ���ƥ��ı��ʽҲ�����֣���������ڣ����Լ�����ƥ��Ŀ����ʽ
//	else if(evaluatedRight->getType(context)->equals(numberType) && matchExpression->getType(context)->equals(numberType))
//	{
//		auto matchNumberExpression = (const Pointer<DoubleExpression> &)(matchExpression);
//		auto myNumberRight = (const Pointer<DoubleExpression> &)(evaluatedRight);
//		if (matchNumberExpression->getValue() > myNumberRight->getValue()) {
//			return evaluatedLeft->match(matchExpression, context);
//		}
//		return false;
//	}
//	else if (evaluatedLeft->getType(context)->equals(numberType) && matchExpression->getType(context)->equals(numberType))
//	{
//		auto matchNumberExpression = (const Pointer<DoubleExpression> &)(matchExpression);
//		auto myNumberExpr = (const Pointer<DoubleExpression> &)(evaluatedLeft);
//		if (matchNumberExpression->getValue() < myNumberExpr->getValue()) {
//			return evaluatedRight->match(matchExpression, context);
//		}
//		return false;
//	}
//	return false;
//}

const Pointer<TypeExpression> GreaterThanExpression::getType(Context *const& context) const
{
	return TypeExpression::GREATER_THAN_EXPRESSION;
}

const Pointer<StringExpression> GreaterThanExpression::toString(Context *const& context)
{
	static Pointer<StringExpression> greaterThan = new StringExpression(L">", ReleaseStrategy::DELETE);
	return BinaryOperatorExpression::toString(context, greaterThan);
}

const Pointer<BooleanExpression> GreaterThanExpression::numberCompareNumber(Context *context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right)const
{
	return left->greaterThan(right);
}
