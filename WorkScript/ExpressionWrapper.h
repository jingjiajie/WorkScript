#pragma once
#include "Expression.h"

class ExpressionWrapper
{
public:
	ExpressionWrapper();
	ExpressionWrapper(const std::shared_ptr<const Expression> &expression);
	const std::shared_ptr<const Expression> & getExpression() const;
	void setExpression(const std::shared_ptr<const Expression> & expression);
protected:
	std::shared_ptr<const Expression> expression;
};