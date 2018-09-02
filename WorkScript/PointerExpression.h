#pragma once
#include "Expression.h"
class PointerExpression :
	public Expression
{
public:
	inline PointerExpression()
	{
		
	}
	virtual ~PointerExpression();

	virtual const Pointer<Expression> getTargetValue() const = 0;
	virtual void setTargetValue(const Pointer<Expression> &ptr) = 0;

	virtual const Pointer<Expression> evaluate(Context *const& context)override;
	virtual void compile(CompileContext *const& context)override;
};

