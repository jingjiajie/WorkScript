#include "GreaterThanExpression.h"
#include "Context.h"

using namespace std;

GreaterThanExpression::GreaterThanExpression(Context * const & context, const std::shared_ptr<const Expression> &leftExpression, const std::shared_ptr<const Expression> &rightExpression)
	:TermExpression(context)
{
	this->setLeftExpression(leftExpression);
	this->setRightExpression(rightExpression);
	this->type = context->findType(TYPENAME_GREATER_THAN_EXPRESSION,false);
}

GreaterThanExpression::~GreaterThanExpression()
{
}


const std::shared_ptr<const Expression> GreaterThanExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto mappedLeft = expressionBind.getMappedExpression(this->leftExpression);
	if (mappedLeft == nullptr)mappedLeft = this->leftExpression;
	auto evaluatedLeft = mappedLeft->evaluate(expressionBind);
	auto mappedRight = expressionBind.getMappedExpression(this->rightExpression);
	if (mappedRight == nullptr)mappedRight = this->rightExpression;
	auto evaluatedRight = mappedRight->evaluate(expressionBind);
	auto numberType = this->context->findType(TYPENAME_NUMBER_EXPRESSION, false);
	if (evaluatedLeft->getType()->equals(numberType) && evaluatedRight->getType()->equals(numberType)) {
		auto boolResult = this->numberGreaterThanNumber(dynamic_pointer_cast<const NumberExpression>(evaluatedLeft), dynamic_pointer_cast<const NumberExpression>(evaluatedRight));
		return boolResult->evaluate(expressionBind);
	}
	else {
		shared_ptr<const GreaterThanExpression> newMe(new GreaterThanExpression(this->context, evaluatedLeft, evaluatedRight));
		auto matchResult = this->matchFirstUpInContextAndEvaluate(newMe);
		return matchResult == nullptr ? newMe : matchResult;
	}
}

bool GreaterThanExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	auto mappedLeft = outExpressionBind->getMappedExpression(this->leftExpression);
	if (mappedLeft == nullptr)mappedLeft = this->leftExpression;
	auto evaluatedLeft = mappedLeft->evaluate(*outExpressionBind);
	auto mappedRight = outExpressionBind->getMappedExpression(this->rightExpression);
	if (mappedRight == nullptr)mappedRight = this->rightExpression;
	auto evaluatedRight = mappedRight->evaluate(*outExpressionBind);
	auto numberType = this->context->findType(TYPENAME_NUMBER_EXPRESSION, false);
	//如果匹配大于表达式，则左右匹配
	if (matchExpression->getType()->equals(this->getType())) {
		auto matchGreaterThanExpression = dynamic_pointer_cast<const GreaterThanExpression>(matchExpression);
		return evaluatedLeft->match(matchGreaterThanExpression->leftExpression, outExpressionBind)
			&& evaluatedRight->match(matchGreaterThanExpression->rightExpression, outExpressionBind);
	}
	//如果自己的右部是数字类型，且匹配的表达式也是数字，则如果大于，将自己的左部匹配目标表达式
	else if(evaluatedRight->getType()->equals(numberType) && matchExpression->getType()->equals(numberType))
	{
		auto matchNumberExpression = dynamic_pointer_cast<const NumberExpression>(matchExpression);
		auto myNumberRight = dynamic_pointer_cast<const NumberExpression>(evaluatedRight);
		if (matchNumberExpression->getValue() > myNumberRight->getValue()) {
			outExpressionBind->addExpressionMap(evaluatedLeft, matchExpression);
			return true;
		}
		return false;
	}
	else if (evaluatedLeft->getType()->equals(numberType) && matchExpression->getType()->equals(numberType))
	{
		auto matchNumberExpression = dynamic_pointer_cast<const NumberExpression>(matchExpression);
		auto myNumberExpr = dynamic_pointer_cast<const NumberExpression>(evaluatedLeft);
		if (matchNumberExpression->getValue() < myNumberExpr->getValue()) {
			outExpressionBind->addExpressionMap(evaluatedRight, matchExpression);
			return true;
		}
		return false;
	}
	return false;
}

bool GreaterThanExpression::equals(const std::shared_ptr<const Expression>&target) const
{
	if (!target->getType()->equals(this->getType()))return false;
	auto targetGreaterThanExpr = dynamic_pointer_cast<const GreaterThanExpression>(target);
	return this->leftExpression->equals(targetGreaterThanExpr->leftExpression)
		&& this->rightExpression->equals(targetGreaterThanExpr->rightExpression);
}

const std::shared_ptr<const TypeExpression> GreaterThanExpression::getType() const
{
	return this->type;
}

const std::string GreaterThanExpression::toString() const
{
	return this->leftExpression->toString() + ">" + this->rightExpression->toString();
}

const std::shared_ptr<const Expression> GreaterThanExpression::getLeftExpression() const
{
	return this->leftExpression;
}

void GreaterThanExpression::setLeftExpression(const std::shared_ptr<const Expression> &expr)
{
	this->leftExpression = expr;
}

const std::shared_ptr<const Expression> GreaterThanExpression::getRightExpression() const
{
	return this->rightExpression;
}

void GreaterThanExpression::setRightExpression(const std::shared_ptr<const Expression> &expr)
{
	this->rightExpression = expr;
}

const std::shared_ptr<const BooleanExpression> GreaterThanExpression::numberGreaterThanNumber(const std::shared_ptr<const NumberExpression> &left, const std::shared_ptr<const NumberExpression> &right)const
{
	shared_ptr<const BooleanExpression> result(new BooleanExpression(this->context, left->getValue() > right->getValue()));
	return result;
}
