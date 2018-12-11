#pragma once
#include "BinaryOperatorExpression.h"

namespace WorkScript {
	class BinaryCalculateExpression :
		public BinaryOperatorExpression
	{
	public:
		inline BinaryCalculateExpression(Expression *left, Expression *right)
			:BinaryOperatorExpression(left, right) { }

		inline BinaryCalculateExpression()
			: BinaryOperatorExpression() { }

		virtual ~BinaryCalculateExpression();
	};
}