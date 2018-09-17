#pragma once
#include "Expression.h"
#include "Context.h"

class Expression;

class ListExpression :
	public Expression
{
public:
	inline ListExpression()
	{
		
	}
	virtual ~ListExpression();

	virtual const Pointer<TypeExpression> getType(Context *const& context) const;
	virtual const Pointer<StringExpression> toString(Context *const& context);
	virtual void link(LinkContext *const& context) override;

	virtual const Pointer<Expression> evaluate(Context *const &context) override;
	virtual bool equals(Context *const &context,const Pointer<Expression> &) const override;
	
	inline const Pointer<Expression> getItem(size_t offset) const
	{
		return this->items[offset];
	}

	inline const size_t addItem(const Pointer<Expression> & termExpression)
	{
		this->items[count] = termExpression;
		count++;
		return count - 1;
	}

	inline const size_t getCount() const {
		return this->count;
	}

private:
	//TODO 静态大小不可以的，要改成动态大小！
	Pointer<Expression> *items = new Pointer<Expression>[10];
	size_t count = 0;
};