#pragma once
#include "GenerateResult.h"
#include "GenerateContext.h"
#include "Expression.h"

namespace WorkScript {

	class Value : public Expression
	{
	public:
		explicit inline Value(const ExpressionInfo &exprInfo) noexcept
				: Expression(exprInfo)	{}
	};
}
