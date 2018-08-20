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

	virtual Expression* const evaluate(Context *const& context)override;
	virtual void compile(CompileContext *const& context)override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context)override;
	virtual bool equals(Context *const &context, Expression* const&) const override;

	inline Context * getTargetContext() const
	{
		return this->targetContext;
	}

	inline void setTargetContext(Context *const &ctx)
	{
		this->targetContext = ctx;
	}

	inline const size_t getOffset() const
	{
		return this->offset;
	}

	inline void setOffset(const size_t &offset)
	{
		this->offset = offset;
	}
protected:
	Context * targetContext = nullptr;
	size_t offset = 0;
};

