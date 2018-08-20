#pragma once
#include "Expression.h"
#include "Expression.h"

class ExpressionWrapper
{
public:
	ExpressionWrapper();
	ExpressionWrapper(Expression* const &expression);
	Expression* const & getExpression() const;
	void setExpression(Expression* const & expression);
protected:
	Expression * expression;
};