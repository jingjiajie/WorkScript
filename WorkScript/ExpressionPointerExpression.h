#pragma once
#include "PointerExpression.h"
class ExpressionPointerExpression :
	public PointerExpression
{
public:
	inline ExpressionPointerExpression(const StorageLevel level)
		:PointerExpression(level)
	{
	}

	inline ExpressionPointerExpression(Expression **const addr, const StorageLevel level)
		: PointerExpression(level)
	{
		this->setTargetAddress(addr);
	}
	virtual ~ExpressionPointerExpression();

	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual StringExpression *const toString(Context *const& context)override;
	virtual bool equals(Context *const &context, Expression* const&) const override;

	inline Expression **const getTargetAddress()const
	{
		return this->ptr;
	}

	inline void setTargetAddress(Expression **const addr)
	{
		this->ptr = addr;
	}

	inline Expression *const getTargetValue() const
	{
		return *this->ptr;
	}

	inline void setTargetValue(Expression *const &ptr)
	{
		*this->ptr = ptr;
	}

protected:
	Expression * *ptr = nullptr;
};

