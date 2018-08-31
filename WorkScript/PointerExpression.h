#pragma once
#include "Expression.h"
class PointerExpression :
	public Expression
{
public:
	inline PointerExpression(const StorageLevel level)
	{
		this->setStorageLevel(level);
	}
	virtual ~PointerExpression();

	virtual Expression *const getTargetValue() const = 0;
	virtual void setTargetValue(Expression *const &ptr) = 0;

	virtual Expression* const evaluate(Context *const& context)override;
	virtual void compile(CompileContext *const& context)override;
};

