#pragma once
#include <string.h>
#include <string>
#include "Expression.h"
#include "ObjectPool.h"
#include "TypeExpression.h"

class StringExpression :
	public Expression
{
	friend class ObjectPool<StringExpression>;
public:
	inline StringExpression(const char *const &value, const StorageLevel level = StorageLevel::TEMP)
	{
		this->setValue(value);
		this->setStorageLevel(level);
	}

	inline static StringExpression *const newInstance(const StorageLevel level = StorageLevel::TEMP)
	{
		auto newInstance = StringExpression::pool.get();
		newInstance->setStorageLevel(level);
		return newInstance;
	}

	inline static StringExpression *const newInstance(const char *const &value, const StorageLevel level = StorageLevel::TEMP)
	{
		auto newInstance = StringExpression::pool.get();
		newInstance->setValue(value);
		newInstance->setStorageLevel(level);
		return newInstance;
	}

	static StringExpression *const combine(const StringExpression *const *const &stringExpressions,const size_t &count, const StorageLevel level = StorageLevel::TEMP);

	inline virtual ~StringExpression()
	{
		if (this->value) delete[] this->value;
	}

	inline virtual StringExpression* const evaluate(Context *const& context) override 
	{
		return this->getStorageLevel() == StorageLevel::LITERAL ? StringExpression::newInstance(this->value) : this;
	}

//	virtual bool match(Expression* const &matchExpression, Context *const& context) const override;

	inline virtual bool equals(Context *const &context, Expression* const& targetExpression) const
	{
		if (targetExpression == this) {
			return true;
		}
		else if (!targetExpression->getType(context)->equals(context, this->getType(context))) {
			return false;
		}
		else {
			return strcmp(((StringExpression *const&)targetExpression)->getValue(), this->value) == 0;
		}
	}

	inline virtual StringExpression *const toString(Context *const& context) override
	{
		return this->evaluate(context);
	}

	inline virtual void compile(CompileContext *const& context) override 
	{
		return;
	}

	inline virtual TypeExpression* const getType(Context *const& context) const override 
	{
		return &TypeExpression::STRING_EXPRESSION;
	}

	inline char *const getValue() const 
	{
		return this->value;
	}

	inline void setValue(const char *const &value) 
	{
		if (this->value)delete[]this->value;
		this->length = strlen(value);
		this->value = new char[length + 1];
		strcpy(this->value,value);
	}

	inline size_t getLength() const
	{
		return this->length;
	}
protected:
	static ObjectPool<StringExpression> pool;

	char *value = nullptr;
	size_t length = 0;
private:
	inline StringExpression() {}

	void release() override;
};

