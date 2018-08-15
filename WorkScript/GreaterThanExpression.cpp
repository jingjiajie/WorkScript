#include "GreaterThanExpression.h"
#include "Context.h"

using namespace std;

GreaterThanExpression::GreaterThanExpression(const std::shared_ptr<TermExpression> &leftExpression, const std::shared_ptr<TermExpression> &rightExpression)
{
	this->setLeftExpression(leftExpression);
	this->setRightExpression(rightExpression);
}

GreaterThanExpression::~GreaterThanExpression()
{
}


const std::shared_ptr<TermExpression> GreaterThanExpression::evaluate(Context *context)
{
	auto evaluatedLeft = this->leftExpression->evaluate(context);
	auto evaluatedRight = this->rightExpression->evaluate(context);
	auto numberType = TypeExpression::NUMBER_EXPRESSION;
	if (evaluatedLeft->getType()->equals(numberType) && evaluatedRight->getType()->equals(numberType)) {
		return this->numberGreaterThanNumber(dynamic_pointer_cast<NumberExpression>(evaluatedLeft), dynamic_pointer_cast<NumberExpression>(evaluatedRight));
	}
	else {
		shared_ptr<GreaterThanExpression> newMe(new GreaterThanExpression(evaluatedLeft, evaluatedRight));
		return newMe;
	}
}
//
//bool GreaterThanExpression::match(const std::shared_ptr<TermExpression>& matchExpression, Context *context) const
//{
//	auto evaluatedLeft = this->leftExpression->evaluate(context);
//	auto evaluatedRight = this->rightExpression->evaluate(context);
//	auto numberType = TypeExpression::NUMBER_EXPRESSION;
//	//如果匹配大于表达式，则左右匹配
//	if (matchExpression->getType()->equals(this->getType())) {
//		auto matchGreaterThanExpression = dynamic_pointer_cast<GreaterThanExpression>(matchExpression);
//		return evaluatedLeft->match(matchGreaterThanExpression->leftExpression, context)
//			&& evaluatedRight->match(matchGreaterThanExpression->rightExpression, context);
//	}
//	//如果自己的右部是数字类型，且匹配的表达式也是数字，则如果大于，将自己的左部匹配目标表达式
//	else if(evaluatedRight->getType()->equals(numberType) && matchExpression->getType()->equals(numberType))
//	{
//		auto matchNumberExpression = dynamic_pointer_cast<NumberExpression>(matchExpression);
//		auto myNumberRight = dynamic_pointer_cast<NumberExpression>(evaluatedRight);
//		if (matchNumberExpression->getValue() > myNumberRight->getValue()) {
//			return evaluatedLeft->match(matchExpression, context);
//		}
//		return false;
//	}
//	else if (evaluatedLeft->getType()->equals(numberType) && matchExpression->getType()->equals(numberType))
//	{
//		auto matchNumberExpression = dynamic_pointer_cast<NumberExpression>(matchExpression);
//		auto myNumberExpr = dynamic_pointer_cast<NumberExpression>(evaluatedLeft);
//		if (matchNumberExpression->getValue() < myNumberExpr->getValue()) {
//			return evaluatedRight->match(matchExpression, context);
//		}
//		return false;
//	}
//	return false;
//}

const std::shared_ptr<TypeExpression> GreaterThanExpression::getType() const
{
	return TypeExpression::GREATER_THAN_EXPRESSION;
}

const std::string GreaterThanExpression::toString() const
{
	return this->leftExpression->toString() + ">" + this->rightExpression->toString();
}

const std::shared_ptr<BooleanExpression> GreaterThanExpression::numberGreaterThanNumber(const std::shared_ptr<NumberExpression> &left, const std::shared_ptr<NumberExpression> &right)const
{
	shared_ptr<BooleanExpression> result(new BooleanExpression(left->getValue() > right->getValue()));
	return result;
}
