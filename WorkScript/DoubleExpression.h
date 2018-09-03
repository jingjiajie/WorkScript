#pragma once
#include "NumberExpression.h"
#include "TypeExpression.h"
#include "ObjectPool.h"

class DoubleExpression :
	public NumberExpression
{
	OBJECT_POOL_MEMBER_DECL(DoubleExpression)
public:
	inline static const Pointer<DoubleExpression> newInstance(const double &value)
	{
		Pointer<DoubleExpression>newInstance = OBJECT_POOL_GET;
		newInstance->value = value;
		return newInstance;
	}

	virtual ~DoubleExpression();

	virtual const Pointer<Expression> evaluate(Context *const& context) override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

	virtual const Pointer<BooleanExpression> equals(const Pointer<Expression>& targetExpression) const;
	virtual const Pointer<BooleanExpression> greaterThan(const Pointer<Expression>& targetExpression) const override;
	virtual const Pointer<BooleanExpression> greaterThanEquals(const Pointer<Expression>& targetExpression) const override;
	virtual const Pointer<BooleanExpression> lessThan(const Pointer<Expression>& targetExpression) const override;
	virtual const Pointer<BooleanExpression> lessThanEquals(const Pointer<Expression>& targetExpression) const override;
	virtual const Pointer<NumberExpression> plus(const Pointer<Expression>& targetExpression) const override;
	virtual const Pointer<NumberExpression> minus(const Pointer<Expression>& targetExpression) const override;
	virtual const Pointer<NumberExpression> multiply(const Pointer<Expression>& targetExpression) const override;
	virtual const Pointer<NumberExpression> divide(const Pointer<Expression>& targetExpression) const override;
	virtual const Pointer<NumberExpression> modulus(const Pointer<Expression>& targetExpression) const override;
	virtual const Pointer<NumberExpression> negate() const override;

	inline virtual const Pointer<TypeExpression> getType(Context *const& context) const override {
		return TypeExpression::DOUBLE_EXPRESSION;
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

