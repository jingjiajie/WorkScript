#pragma once
#include "NumberExpression.h"
#include "ObjectPool.h"
class ByteExpression :
	public NumberExpression
{
	OBJECT_POOL_MEMBER_DECL(ByteExpression);
	inline ByteExpression() {}
public:
	virtual ~ByteExpression();

	inline static ByteExpression *const newInstance(const unsigned char &value, const StorageLevel level = StorageLevel::TEMP)
	{
		auto newInstance = OBJECT_POOL_GET;
		newInstance->setStorageLevel(level);
		newInstance->value = value;
		return newInstance;
	}


	virtual Expression* const evaluate(Context *const& context) override;
	virtual StringExpression *const toString(Context *const& context) override;

	virtual BooleanExpression *const equals(Expression* const& targetExpression) const;
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
		return &TypeExpression::BYTE_EXPRESSION;
	}

	inline const unsigned char getValue() const {
		return this->value;
	}

	inline void setValue(const unsigned char &value) {
		this->value = value;
	}

	virtual void release()override {
		OBJECT_POOL_PUSH(this);
	}
protected:
	unsigned char value;
};