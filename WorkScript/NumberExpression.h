#pragma once
#include "Expression.h"
#include "TypeExpression.h"

class BooleanExpression;

class NumberExpression :
	public Expression
{
public:
	inline NumberExpression(const StorageLevel level) {
		this->setStorageLevel(level);
	}
	inline NumberExpression() {}
	virtual ~NumberExpression();

	virtual void compile(CompileContext *const& context) override;

	virtual bool equals(Context *const &context, Expression* const& targetExpression) const override;
	virtual BooleanExpression *const equals(Expression* const& targetExpression) const = 0;
	virtual BooleanExpression *const greaterThan(Expression* const& targetExpression) const = 0;
	virtual BooleanExpression *const greaterThanEquals(Expression* const& targetExpression) const = 0;
	virtual BooleanExpression *const lessThan(Expression* const& targetExpression) const = 0;
	virtual BooleanExpression *const lessThanEquals(Expression* const& targetExpression) const = 0;
	virtual NumberExpression *const plus(Expression* const& targetExpression) const = 0;
	virtual NumberExpression *const minus(Expression* const& targetExpression) const = 0;
	virtual NumberExpression *const multiply(Expression* const& targetExpression) const = 0;
	virtual NumberExpression *const divide(Expression* const& targetExpression) const = 0;
	virtual NumberExpression *const modulus(Expression* const& targetExpression) const = 0;
};