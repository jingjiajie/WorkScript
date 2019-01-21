#pragma once
#include "Expression.h"

namespace WorkScript {
	class ExpressionWrapper
	{
	public:
		inline ExpressionWrapper(Expression *expr) noexcept
			:expression(expr) {	}

		inline ExpressionWrapper(const ExpressionWrapper &wrapper) noexcept
			:expression(wrapper.expression) {	}

		inline Expression * getExpression() const
		{
			return this->expression;
		}

		inline void setExpression(Expression * expression)
		{
			this->expression = expression;
		}

		operator Expression*() {
			return this->expression;
		}
	protected:
		Expression * expression;
	};

}