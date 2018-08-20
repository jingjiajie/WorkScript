#pragma once
#include "Expression.h"
class ParameterExpression :
	public Expression
{
public:
	inline ParameterExpression(const size_t &count, const StorageLevel level = StorageLevel::TEMP)
	{
		this->items = new Expression*[count];
		this->count = count;
		this->storageLevel = level;
	}

	virtual ~ParameterExpression();

	virtual TypeExpression* const getType(Context *const& context) const;
	virtual StringExpression *const toString(Context *const& context);
	virtual void compile(CompileContext *const& context) override;

	virtual Expression* const evaluate(Context *const &context) override;
	virtual bool equals(Context *const &context, Expression* const&) const override;

	inline Expression* const getItem(const size_t &offset) const
	{
		return this->items[offset];
	}

	inline void setItem(const size_t &offset, Expression* const& termExpression)
	{
		this->items[offset] = termExpression;
	}

	inline const size_t getCount() const {
		return this->count;
	}

protected:
	Expression **items;
	size_t count = 0;
};

