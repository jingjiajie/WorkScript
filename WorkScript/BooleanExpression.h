#pragma once
#include "Expression.h"
#include "TypeExpression.h"
#include "ObjectPool.h"
class BooleanExpression :
	public Expression
{
public:
	inline static const Pointer<BooleanExpression> newInstance(const unsigned char value)
	{
		auto newInstance = OBJECT_POOL_GET;
		newInstance->value = value;
		return newInstance;
	}

	virtual ~BooleanExpression();

	virtual const Pointer<Expression> evaluate(Context *const& context) override;
	//virtual bool match(const Pointer<Expression> &matchExpression, Context *const& context) const override;
	virtual bool equals(Context *const &context, const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;

	inline virtual void link(LinkContext *const& context) override{}

	inline virtual const Pointer<TypeExpression> getType(Context *const& context) const override {
		return TypeExpression::BOOLEAN_EXPRESSION;
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
		OBJECT_POOL_PUSH(this);
	}
public:
	static Pointer<BooleanExpression> VAL_TRUE, VAL_YES, VAL_OK, VAL_GOOD, VAL_FALSE, VAL_NO, VAL_BAD;
	static Pointer<StringExpression> STR_TRUE, STR_YES, STR_OK, STR_GOOD, STR_FALSE, STR_NO, STR_BAD;
	OBJECT_POOL_MEMBER_DECL(BooleanExpression);

private:
	inline BooleanExpression() {}
	inline BooleanExpression(const unsigned char value,ReleaseStrategy releaseStrategy = ReleaseStrategy::CALL_RELEASE)
	{
		this->value = value;
		this->releaseStrategy = releaseStrategy;
	}
};

