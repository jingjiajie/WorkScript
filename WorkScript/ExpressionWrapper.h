#pragma once
#include "Expression.h"
#include "TermExpression.h"

class ExpressionWrapper
{
public:
	ExpressionWrapper();
	ExpressionWrapper(const std::shared_ptr<Expression> &expression);
	const std::shared_ptr<Expression> & getExpression() const;
	const std::shared_ptr<TermExpression> & getTermExpression() const;
	void setExpression(const std::shared_ptr<Expression> & expression);
protected:
	std::shared_ptr<Expression> expression;
};