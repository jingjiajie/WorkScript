#pragma once
#include "Expression.h"
#include "TypeExpression.h"
#include "ObjectPool.h"
class BooleanExpression :
	public Expression
{
	friend class ObjectPool<BooleanExpression>;
public:
	inline static BooleanExpression *const newInstance(const unsigned char value, const StorageLevel level = StorageLevel::TEMP)
	{
		auto newInstance = BooleanExpression::pool.get();
		newInstance->value = value;
		newInstance->setStorageLevel(level);
		return newInstance;
	}

	virtual ~BooleanExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual bool equals(Context *const &context, Expression* const& targetExpression) const override;
	virtual StringExpression *const toString(Context *const& context) override;

	inline virtual void compile(CompileContext *const& context) override{}

	inline virtual TypeExpression* const getType(Context *const& context) const override {
		return &TypeExpression::BOOLEAN_EXPRESSION;
	}

	inline const unsigned char getValue() const {
		return this->value;
	}

	inline void setValue(unsigned char &value) {
		this->value = value;
	}

protected:
	unsigned char value;

	virtual void release() override	
	{
		BooleanExpression::pool.push(this);
	}
public:
	static BooleanExpression VAL_YES, VAL_NO, VAL_TRUE, VAL_FALSE;
	static StringExpression STR_TRUE, STR_FALSE, STR_YES, STR_NO;
	static ObjectPool<BooleanExpression> pool;

private:
	inline BooleanExpression() {}
	inline BooleanExpression(const unsigned char value, const StorageLevel level = StorageLevel::TEMP)
	{
		this->value = value;
		this->setStorageLevel(level);
	}
};

