#include "GreaterThanExpression.h"
#include "StringExpression.h"
#include "Context.h"
#include "Program.h"

using namespace std;

GreaterThanExpression::~GreaterThanExpression()
{
}

//
//bool GreaterThanExpression::match(Expression* const& matchExpression, Context *const& context) const
//{
//	auto evaluatedLeft = this->leftExpression->evaluate(context);
//	auto evaluatedRight = this->rightExpression->evaluate(context);
//	auto numberType = &TypeExpression::NUMBER_EXPRESSION;
//	//���ƥ����ڱ��ʽ��������ƥ��
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchGreaterThanExpression = (GreaterThanExpression *const&)(matchExpression);
//		return evaluatedLeft->match(matchGreaterThanExpression->leftExpression, context)
//			&& evaluatedRight->match(matchGreaterThanExpression->rightExpression, context);
//	}
//	//����Լ����Ҳ����������ͣ���ƥ��ı��ʽҲ�����֣���������ڣ����Լ�����ƥ��Ŀ����ʽ
//	else if(evaluatedRight->getType(context)->equals(numberType) && matchExpression->getType(context)->equals(numberType))
//	{
//		auto matchNumberExpression = (DoubleExpression *const&)(matchExpression);
//		auto myNumberRight = (DoubleExpression *const&)(evaluatedRight);
//		if (matchNumberExpression->getValue() > myNumberRight->getValue()) {
//			return evaluatedLeft->match(matchExpression, context);
//		}
//		return false;
//	}
//	else if (evaluatedLeft->getType(context)->equals(numberType) && matchExpression->getType(context)->equals(numberType))
//	{
//		auto matchNumberExpression = (DoubleExpression *const&)(matchExpression);
//		auto myNumberExpr = (DoubleExpression *const&)(evaluatedLeft);
//		if (matchNumberExpression->getValue() < myNumberExpr->getValue()) {
//			return evaluatedRight->match(matchExpression, context);
//		}
//		return false;
//	}
//	return false;
//}

TypeExpression* const GreaterThanExpression::getType(Context *const& context) const
{
	return &TypeExpression::GREATER_THAN_EXPRESSION;
}

StringExpression *const GreaterThanExpression::toString(Context *const& context)
{
	static StringExpression greaterThan(L">",StorageLevel::EXTERN);
	return BinaryOperatorExpression::toString(context, &greaterThan);
}

BooleanExpression* const GreaterThanExpression::numberCompareNumber(Context *context, NumberExpression* const &left, NumberExpression* const &right)const
{
	return left->greaterThan(right);
}
