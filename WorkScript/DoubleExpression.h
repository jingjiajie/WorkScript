#pragma once
#include "NumberExpression.h"
#include "TypeExpression.h"
#include "ObjectPool.h"

class DoubleExpression :
	public NumberExpression
{
	OBJECT_POOL_MEMBER_DECL(DoubleExpression)
public:
	inline static DoubleExpression *const newInstance(const double &value, const StorageLevel level = StorageLevel::TEMP)
	{
		DoubleExpression *newInstance = OBJECT_POOL_GET;
		newInstance->setStorageLevel(level);
		newInstance->value = value;
		return newInstance;
	}

	virtual ~DoubleExpression();

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
		return &TypeExpression::DOUBLE_EXPRESSION;
	}

	inline const double getValue() const {
		return this->value;
	}

	inline void setValue(const double &value) {
		this->value = value;
	}
protected:
	double value;

	virtual void release() override
	{
		OBJECT_POOL_PUSH(this);
	}
private:
	inline DoubleExpression() {}; //私有构造函数，只有对象池能访问
};

