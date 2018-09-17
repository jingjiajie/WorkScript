#pragma once
#include "Expression.h"
class ParameterExpression :
	public Expression
{
public:
	inline ParameterExpression(Pointer<Expression> *const& items, const size_t &count)
	{
		this->setItems(items,count);
	}

	virtual ~ParameterExpression();

	virtual const Pointer<TypeExpression> getType(Context *const& context) const;
	virtual const Pointer<StringExpression> toString(Context *const& context);
	virtual void link(LinkContext *const& context) override;

	virtual const Pointer<Expression> evaluate(Context *const &context) override;
	virtual bool equals(Context *const &context, const Pointer<Expression> &) const override;

	inline Pointer<Expression> *const getItems() const
	{
		return this->items;
	}

	inline const Pointer<Expression> getItem(const size_t &index)const
	{
		return this->items[index];
	}

	inline void setItems(Pointer<Expression> *const& items, const size_t &count)
	{
		this->items = items;
		this->count = count;
		this->flat(nullptr);
	}

	inline const size_t getCount() const {
		return this->count;
	}

	void flat(Context *const &context);

protected:
	Pointer<Expression> *items;
	size_t count;
};

