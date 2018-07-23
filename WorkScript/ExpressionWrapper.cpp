#include "ExpressionWrapper.h"

ExpressionWrapper::ExpressionWrapper()
{
}

ExpressionWrapper::ExpressionWrapper(const std::shared_ptr<const Expression> &expression)
{
	this->setExpression(expression);
}

const std::shared_ptr<const Expression> & ExpressionWrapper::getExpression() const
{
	return this->expression;
}

void ExpressionWrapper::setExpression(const std::shared_ptr<const Expression> &expression)
{
	this->expression = expression;
}
