#include "ThisExpression.h"
#include "TypeExpression.h"
#include "Context.h"

ThisExpression::ThisExpression(Context * const & context)
	:PolynomialExpression(context)
{

}

ThisExpression::~ThisExpression()
{
}

const std::shared_ptr<const Expression> ThisExpression::evaluate(const ExpressionBind &) const
{
	return this->context->getCurrentExpression();
}

bool ThisExpression::match(const std::shared_ptr<const Expression>& matchExpression, ExpressionBind * outExpressionBind) const
{
	if (!this->equals(matchExpression))return false;
	outExpressionBind->addExpressionMap(this->shared_from_this(), matchExpression);
	return true;
}

bool ThisExpression::equals(const std::shared_ptr<const Expression> &target) const
{
	if (!target->getType()->equals(this->getType()))return false;
	if (!this->context->getCurrentExpression()->equals(target))return false;
	return true;
}

const std::shared_ptr<const TypeExpression> ThisExpression::getType() const
{
	return this->context->findType(TYPENAME_THIS_EXPRESSION,false);
}