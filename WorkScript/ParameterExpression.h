#pragma once
#include "Expression.h"
class ParameterExpression :
	public Expression
{
public:
	inline ParameterExpression(Expression** const& items, const size_t &count, const StorageLevel level = StorageLevel::TEMP)
	{
		this->setItems(items,count);
		this->storageLevel = level;
	}

	virtual ~ParameterExpression();

	virtual TypeExpression* const getType(Context *const& context) const;
	virtual StringExpression *const toString(Context *const& context);
	virtual void compile(CompileContext *const& context) override;

	virtual Expression* const evaluate(Context *const &context) override;
	virtual bool equals(Context *const &context, Expression* const&) const override;

	inline Expression** const getItems() const
	{
		return this->items;
	}

	inline Expression *const getItem(const size_t &index)const
	{
		return this->items[index];
	}

	inline void setItems(Expression** const& items, const size_t &count)
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
	Expression **items;
	size_t count;
};

