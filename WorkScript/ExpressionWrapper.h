#pragma once
#include "Expression.h"

enum class ExpressionLifeCycle : unsigned char {
	COMPILE,ALL
};

class ExpressionWrapper
{
public:
	inline ExpressionWrapper() {}

	inline ExpressionWrapper(const Pointer<Expression> &expr) noexcept
		:expression(expr)
	{

	}

	inline ExpressionWrapper(const ExpressionWrapper &wrapper) noexcept
		:expression(wrapper.expression),lifeCycle(wrapper.lifeCycle)
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

	inline ExpressionLifeCycle getLifeCycle()const
	{
		return this->lifeCycle;
	}

	inline void setLifeCycle(ExpressionLifeCycle lifeCycle)
	{
		this->lifeCycle = lifeCycle;
	}

protected:
	Pointer<Expression> expression;
	ExpressionLifeCycle lifeCycle = ExpressionLifeCycle::ALL;
};