#pragma once
#include "TermExpression.h"
#include "Context.h"

class TermExpression;

class ListExpression :
	public TermExpression
{
public:
	ListExpression();
	virtual ~ListExpression();

	virtual const std::shared_ptr<TypeExpression> getType() const;
	virtual const std::string toString() const;
	virtual void compile(CompileContext *context) override;

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	virtual bool equals(const std::shared_ptr<TermExpression>&) const override;
	
	inline const std::shared_ptr<TermExpression> getItem(size_t offset) const
	{
		return this->items[offset];
	}

	inline const size_t addItem(const std::shared_ptr<TermExpression>& termExpression)
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
	std::shared_ptr<TermExpression> items[10];
	size_t count = 0;
};