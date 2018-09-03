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

	inline static const Pointer<ByteExpression> newInstance(const unsigned char &value)
	{
		auto newInstance = OBJECT_POOL_GET;
		newInstance->value = value;
		return newInstance;
	}


	virtual const Pointer<Expression> evaluate(Context *const& context) override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

	virtual const Pointer<BooleanExpression> equals(const Pointer<Expression> & targetExpression) const;
	virtual const Pointer<BooleanExpression> greaterThan(const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<BooleanExpression> greaterThanEquals(const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<BooleanExpression> lessThan(const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<BooleanExpression> lessThanEquals(const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<NumberExpression> plus(const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<NumberExpression> minus(const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<NumberExpression> multiply(const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<NumberExpression> divide(const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<NumberExpression> modulus(const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<NumberExpression> negate() const override;

	inline virtual const Pointer<TypeExpression> getType(Context *const& context) const override {
		return TypeExpression::BYTE_EXPRESSION;
	}

	inline const unsigned char getValue() const {
		return this->value;
	}

	inline void setValue(const unsigned char &value) {
		this->value = value;
	}
protected:
	unsigned char value;

	virtual void release()override {
		OBJECT_POOL_PUSH(this);
	}
};