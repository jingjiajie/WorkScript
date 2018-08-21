#include "GreaterThanExpression.h"
#include "StringExpression.h"
#include "Context.h"
#include "Program.h"

using namespace std;

GreaterThanExpression::~GreaterThanExpression()
{
}


Expression* const GreaterThanExpression::evaluate(Context *const& context)
{
	auto evaluatedLeft = this->leftExpression->evaluate(context);
	auto evaluatedRight = this->rightExpression->evaluate(context);
	auto numberType = &TypeExpression::NUMBER_EXPRESSION;
	Expression *ret;
	auto leftType = evaluatedLeft->getType(context);
	auto rightType = evaluatedRight->getType(context);
	if (leftType->equals(context, numberType) && rightType->equals(context, numberType)) {
		ret = this->numberGreaterThanNumber((NumberExpression *const&)(evaluatedLeft), (NumberExpression *const&)(evaluatedRight));
		goto OK;
	}
	else {
		ret = new GreaterThanExpression(evaluatedLeft, evaluatedRight);
		goto OK;
	}

OK:
	evaluatedLeft->releaseTemp();
	evaluatedRight->releaseTemp();
	leftType->releaseTemp();
	rightType->releaseTemp();
	return ret;
}
//
//bool GreaterThanExpression::match(Expression* const& matchExpression, Context *const& context) const
//{
//	auto evaluatedLeft = this->leftExpression->evaluate(context);
//	auto evaluatedRight = this->rightExpression->evaluate(context);
//	auto numberType = &TypeExpression::NUMBER_EXPRESSION;
//	//如果匹配大于表达式，则左右匹配
//	if (matchExpression->getType(context)->equals(this->getType(context))) {
//		auto matchGreaterThanExpression = (GreaterThanExpression *const&)(matchExpression);
//		return evaluatedLeft->match(matchGreaterThanExpression->leftExpression, context)
//			&& evaluatedRight->match(matchGreaterThanExpression->rightExpression, context);
//	}
//	//如果自己的右部是数字类型，且匹配的表达式也是数字，则如果大于，将自己的左部匹配目标表达式
//	else if(evaluatedRight->getType(context)->equals(numberType) && matchExpression->getType(context)->equals(numberType))
//	{
//		auto matchNumberExpression = (NumberExpression *const&)(matchExpression);
//		auto myNumberRight = (NumberExpression *const&)(evaluatedRight);
//		if (matchNumberExpression->getValue() > myNumberRight->getValue()) {
//			return evaluatedLeft->match(matchExpression, context);
//		}
//		return false;
//	}
//	else if (evaluatedLeft->getType(context)->equals(numberType) && matchExpression->getType(context)->equals(numberType))
//	{
//		auto matchNumberExpression = (NumberExpression *const&)(matchExpression);
//		auto myNumberExpr = (NumberExpression *const&)(evaluatedLeft);
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
	static StringExpression greaterThan(">",StorageLevel::EXTERN);
	return BinaryTermExpression::toString(context, &greaterThan);
}

BooleanExpression* const GreaterThanExpression::numberGreaterThanNumber(NumberExpression* const &left, NumberExpression* const &right)const
{
	return BooleanExpression::newInstance(left->getValue() > right->getValue());
}
