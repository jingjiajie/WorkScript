#pragma once
#include "Expression.h"

namespace WorkScript {

	enum class ExpressionLifeCycle : unsigned char {
		COMPILE, ALL
	};

	class ExpressionWrapper
	{
	public:
		inline ExpressionWrapper() {}

		inline ExpressionWrapper(Expression *expr) noexcept
			:expression(expr)
		{

		}

		inline ExpressionWrapper(const ExpressionWrapper &wrapper) noexcept
			:expression(wrapper.expression), lifeCycle(wrapper.lifeCycle)
		{

		}

		inline Expression * getExpression() const
		{
			return this->expression;
		}

		inline void setExpression(Expression * expression)
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
		Expression * expression;
		ExpressionLifeCycle lifeCycle = ExpressionLifeCycle::ALL;
	};

}