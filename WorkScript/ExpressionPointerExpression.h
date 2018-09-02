#pragma once
#include "PointerExpression.h"
class ExpressionPointerExpression :
	public PointerExpression
{
public:
	inline ExpressionPointerExpression()
		:PointerExpression()
	{
	}

	inline ExpressionPointerExpression(Pointer<Expression> *const addr)
		: PointerExpression()
	{
		this->setTargetAddress(addr);
	}
	virtual ~ExpressionPointerExpression();

	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context)override;
	virtual bool equals(Context *const &context, const Pointer<Expression>&) const override;

	inline Pointer<Expression> *const getTargetAddress()const
	{
		return this->ptr;
	}

	inline void setTargetAddress(Pointer<Expression> *const addr)
	{
		this->ptr = addr;
	}

	inline const Pointer<Expression> getTargetValue() const
	{
		return *this->ptr;
	}

	inline void setTargetValue(const Pointer<Expression> &ptr)
	{
		*this->ptr = ptr;
	}

protected:
	Pointer<Expression>  *ptr = nullptr;
};

