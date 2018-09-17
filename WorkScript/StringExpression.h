#pragma once
#include <string.h>
#include <string>
#include "Expression.h"
#include "ObjectPool.h"
#include "TypeExpression.h"

class StringExpression :
	public Expression
{
public:
	inline StringExpression(const wchar_t *const &value,const ReleaseStrategy releaseStrategy)
	{
		this->setValue(value);
		this->releaseStrategy = releaseStrategy;
	}

	inline static const Pointer<StringExpression> newInstance()
	{
		auto newInstance = OBJECT_POOL_GET;
		return newInstance;
	}

	inline static const Pointer<StringExpression> newInstance(const wchar_t *const &value)
	{
		auto newInstance = OBJECT_POOL_GET;
		newInstance->setValue(value);
		return newInstance;
	}

	static const Pointer<StringExpression> combine(const Pointer<StringExpression> *const &stringExpressions,const size_t &count);

	inline virtual ~StringExpression()
	{
		if (this->value) delete[] this->value;
	}

	inline virtual const Pointer<Expression> evaluate(Context *const& context) override 
	{
		return this;
	}

//	virtual bool match(const Pointer<Expression> &matchExpression, Context *const& context) const override;

	inline virtual bool equals(Context *const &context, const Pointer<Expression> & targetExpression) const
	{
		if (targetExpression == this) {
			return true;
		}
		else if (!targetExpression->getType(context)->equals(context, this->getType(context))) {
			return false;
		}
		else {
			auto targetStrExpr = ((const Pointer<StringExpression> &)targetExpression);
			if (this->getLength() != targetStrExpr->getLength())return false;
			for (size_t i = 0; i < targetStrExpr->getLength(); ++i) {
				if (this->value[i] != targetStrExpr->value[i])return false;
			}
			return true;
		}
	}

	inline virtual const Pointer<StringExpression> toString(Context *const& context) override
	{
		return this->evaluate(context);
	}

	inline virtual void link(LinkContext *const& context) override 
	{
		return;
	}

	inline virtual const Pointer<TypeExpression> getType(Context *const& context) const override 
	{
		return TypeExpression::STRING_EXPRESSION;
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
	OBJECT_POOL_MEMBER_DECL(StringExpression);

	wchar_t *value = nullptr;
	size_t length = 0;
private:
	inline StringExpression() {}

	void release() override;
};

