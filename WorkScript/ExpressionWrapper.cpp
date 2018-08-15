#include "ExpressionWrapper.h"
#include <memory>
using namespace std;

ExpressionWrapper::ExpressionWrapper()
{
}

ExpressionWrapper::ExpressionWrapper(const std::shared_ptr<Expression> &expression)
{
	this->setExpression(expression);
}

const std::shared_ptr<Expression> & ExpressionWrapper::getExpression() const
{
	return this->expression;
}

const std::shared_ptr<TermExpression>& ExpressionWrapper::getTermExpression() const
{
	//这里不可以用dynamic_pointer_cast!
	return (const std::shared_ptr<TermExpression>&)this->expression;
}

void ExpressionWrapper::setExpression(const std::shared_ptr<Expression> &expression)
{
	this->expression = expression;
}
