#include "RelationExpression.h"
#include "Context.h"
#include "TypeExpression.h"

using namespace std;

RelationExpression::RelationExpression(Context *const &context, const shared_ptr<const Expression> &leftExpression, const shared_ptr<const Expression> &rightExpression)
	:Expression(context)
{
	this->setLeftAndRightExpression(leftExpression,rightExpression);
}

RelationExpression::~RelationExpression()
{

}

const std::shared_ptr<const Expression> RelationExpression::evaluate(const ExpressionBind &expressionBind) const
{
	auto mappedRight = expressionBind.getMappedExpression(this->rightExpression);
	if (mappedRight == nullptr)mappedRight = this->rightExpression;
	auto resultExpr = mappedRight->evaluate(expressionBind);
	return resultExpr;
}

const std::shared_ptr<const TypeExpression> RelationExpression::getType() const
{
	return this->context->findType(TYPENAME_RELATION_EXPRESSION,false);
}

const std::string RelationExpression::toString() const
{
	return this->leftExpression->toString() + " = " + this->rightExpression->toString();
}

bool RelationExpression::equals(const std::shared_ptr<const Expression> &targetExpression) const
{
	if (!targetExpression->getType()->equals(this->getType())) return false;
	const RelationExpression *const &targetRelationExpression = (const RelationExpression *const &)targetExpression;
	return targetRelationExpression->getLeftExpression()->equals(this->leftExpression)
		&& targetRelationExpression->getRightExpression()->equals(this->rightExpression);
}

bool RelationExpression::match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const
{
	auto ret = this->leftExpression->match(matchExpression, outExpressionBind);
	return ret;
}

void RelationExpression::setLeftAndRightExpression(const std::shared_ptr<const Expression>& leftExpression, const std::shared_ptr<const Expression>& rightExpression)
{
	this->leftExpression = leftExpression;
	this->rightExpression = rightExpression;
}

const shared_ptr<const Expression> & RelationExpression::getLeftExpression() const
{
	return this->leftExpression;
}

const shared_ptr<const Expression> & RelationExpression::getRightExpression() const
{
	return this->rightExpression;
}

