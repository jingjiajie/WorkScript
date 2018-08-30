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
	inline StringExpression(const wchar_t *const &value, const StorageLevel level = StorageLevel::TEMP)
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

	inline static StringExpression *const newInstance(const wchar_t *const &value, const StorageLevel level = StorageLevel::TEMP)
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
			auto targetStrExpr = ((StringExpression *const&)targetExpression);
			if (this->getLength() != targetStrExpr->getLength())return false;
			for (size_t i = 0; i < targetStrExpr->getLength(); ++i) {
				if (this->value[i] != targetStrExpr->value[i])return false;
			}
			return true;
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

	inline wchar_t *const getValue() const 
	{
		return this->value;
	}

	inline void setValue(const wchar_t *const &value) 
	{
		if (this->value)delete[]this->value;
		this->length = wcslen(value);
		this->value = new wchar_t[length + 1];
		wcscpy(this->value,value);
	}

	inline size_t getLength() const
	{
		return this->length;
	}
protected:
	static ObjectPool<StringExpression> pool;

	wchar_t *value = nullptr;
	size_t length = 0;
private:
	inline StringExpression() {}

	void release() override;
};

