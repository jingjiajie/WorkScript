#include "ExpressionWrapper.h"
using namespace std;

ExpressionWrapper::ExpressionWrapper()
{
}

ExpressionWrapper::ExpressionWrapper(Expression* const &expression)
{
	this->setExpression(expression);
}

Expression* const & ExpressionWrapper::getExpression() const
{
	return this->expression;
}

Expression* const& ExpressionWrapper::getTermExpression() const
{
	return (Expression* const&)this->expression;
}

void ExpressionWrapper::setExpression(Expression* const &expression)
{
	this->expression = expression;
}
