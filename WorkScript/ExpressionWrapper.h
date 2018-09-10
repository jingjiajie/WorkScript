#pragma once
#include "Expression.h"

class ExpressionWrapper
{
public:
	inline ExpressionWrapper() {}

	inline ExpressionWrapper(const Pointer<Expression> &expr) noexcept
		:expression(expr)
	{

	}

	inline ExpressionWrapper(const ExpressionWrapper &wrapper) noexcept
		:expression(wrapper.expression)
	{

	}

	inline const Pointer<Expression> getExpression() const
	{
		return this->expression;
	}

	inline void setExpression(const Pointer<Expression> & expression)
	{
		this->expression = expression;
	}

protected:
	Pointer<Expression> expression;
};