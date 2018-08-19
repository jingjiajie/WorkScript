#pragma once
#include "Expression.h"
#include "Context.h"

class Expression;

class ListExpression :
	public Expression
{
public:
	inline ListExpression(const StorageLevel level = StorageLevel::TEMP)
	{
		this->setStorageLevel(level);
	}
	virtual ~ListExpression();

	virtual TypeExpression* const getType(Context *const& context) const;
	virtual StringExpression *const toString(Context *const& context);
	virtual void compile(CompileContext *const& context) override;

	virtual Expression* const evaluate(Context *const &context) override;
	virtual bool equals(Context *const &context,Expression* const&) const override;
	
	inline Expression* const getItem(size_t offset) const
	{
		return this->items[offset];
	}

	inline const size_t addItem(Expression* const& termExpression)
	{
		this->items[count] = termExpression;
		count++;
		return count - 1;
	}

	inline const size_t getCount() const {
		return this->count;
	}

private:
	//TODO ��̬��С�����Եģ�Ҫ�ĳɶ�̬��С��
	Expression * items[10];
	size_t count = 0;
};