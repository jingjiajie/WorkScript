#include "Expression.h"
#include "Context.h"

Expression::Expression(Context *const &context)
{
	this->context = context;
}

Expression::~Expression()
{
}

const Context *const & Expression::getContext() const
{
	return this->context;
}

void Expression::setContext(Context *const &context)
{
	this->context = context;
}

const std::vector<std::shared_ptr<const TypeMemberExpression>> Expression::getInstantialExpressions() const
{
	return this->instantialExpressions;
}

void Expression::addInstantialExpressions(const std::shared_ptr<const TypeMemberExpression>& expr)
{
	this->instantialExpressions.push_back(expr);
}

