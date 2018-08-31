#pragma once
#include "NumberExpression.h"
#include "ObjectPool.h"

class IntegerExpression :
	public NumberExpression
{
	OBJECT_POOL_MEMBER_DECL(IntegerExpression);
	inline IntegerExpression() {}
public:
	virtual ~IntegerExpression();

	inline static IntegerExpression *const newInstance(const int &value, const StorageLevel level = StorageLevel::TEMP)
	{
		auto newInstance = OBJECT_POOL_GET;
		newInstance->setStorageLevel(level);
		newInstance->value = value;
		return newInstance;
	}

	virtual Expression* const evaluate(Context *const& context) override;
	virtual StringExpression *const toString(Context *const& context) override;

	virtual BooleanExpression *const equals(Expression* const& targetExpression) const override;
	virtual BooleanExpression *const greaterThan(Expression* const& targetExpression) const override;
	virtual BooleanExpression *const greaterThanEquals(Expression* const& targetExpression) const override;
	virtual BooleanExpression *const lessThan(Expression* const& targetExpression) const override;
	virtual BooleanExpression *const lessThanEquals(Expression* const& targetExpression) const override;
	virtual NumberExpression *const plus(Expression* const& targetExpression) const override;
	virtual NumberExpression *const minus(Expression* const& targetExpression) const override;
	virtual NumberExpression *const multiply(Expression* const& targetExpression) const override;
	virtual NumberExpression *const divide(Expression* const& targetExpression) const override;
	virtual NumberExpression *const modulus(Expression* const& targetExpression) const override;

	inline virtual TypeExpression* const getType(Context *const& context) const override {
		return &TypeExpression::INTEGER_EXPRESSION;
	}

	inline const int getValue() const {
		return this->value;
	}

	inline void setValue(const int &value) {
		this->value = value;
	}
protected:
	int value;

	virtual void release()override {
		OBJECT_POOL_PUSH(this);
	}
};

