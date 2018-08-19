#pragma once
#include "Expression.h"
#include "TypeExpression.h"
#include "ObjectPool.h"

class NumberExpression :
	public Expression
{
	friend class ObjectPool<NumberExpression>;
public:
	inline static NumberExpression *const newInstance(const double &value, const StorageLevel level = StorageLevel::TEMP)
	{
		auto newInstance = NumberExpression::pool.get();
		newInstance->setStorageLevel(level);
		newInstance->value = value;
		return newInstance;
	}

	virtual ~NumberExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual bool equals(Context *const &context, Expression* const& targetExpression) const;
	virtual StringExpression *const toString(Context *const& context) override;
	virtual void compile(CompileContext *const& context) override;

	inline virtual TypeExpression* const getType(Context *const& context) const override {
		return &TypeExpression::NUMBER_EXPRESSION;
	}

	inline const double getValue() const {
		return this->value;
	}

	inline void setValue(const double &value) {
		this->value = value;
	}
protected:
	double value;
	static ObjectPool<NumberExpression> pool; //对象池

	virtual void release() override
	{
		//if (pool.count > 0 && pool.buff[pool.count - 1] == this) {
		//	throw ("重复释放！");
		//	return;
		//}
		NumberExpression::pool.push(this);
	}
private:
	inline NumberExpression() {}; //私有构造函数，只有对象池能访问
};

