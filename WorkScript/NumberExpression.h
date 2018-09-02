#pragma once
#include "Expression.h"
#include "TypeExpression.h"

class BooleanExpression;

class NumberExpression :
	public Expression
{
public:
	inline NumberExpression() {
		
	}
	virtual ~NumberExpression();

	virtual void compile(CompileContext *const& context) override;

	virtual bool equals(Context *const &context, const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<BooleanExpression> equals(const Pointer<Expression> & targetExpression) const = 0;
	virtual const Pointer<BooleanExpression> greaterThan(const Pointer<Expression> & targetExpression) const = 0;
	virtual const Pointer<BooleanExpression> greaterThanEquals(const Pointer<Expression> & targetExpression) const = 0;
	virtual const Pointer<BooleanExpression> lessThan(const Pointer<Expression> & targetExpression) const = 0;
	virtual const Pointer<BooleanExpression> lessThanEquals(const Pointer<Expression> & targetExpression) const = 0;
	virtual const Pointer<NumberExpression> plus(const Pointer<Expression> & targetExpression) const = 0;
	virtual const Pointer<NumberExpression> minus(const Pointer<Expression> & targetExpression) const = 0;
	virtual const Pointer<NumberExpression> multiply(const Pointer<Expression> & targetExpression) const = 0;
	virtual const Pointer<NumberExpression> divide(const Pointer<Expression> & targetExpression) const = 0;
	virtual const Pointer<NumberExpression> modulus(const Pointer<Expression> & targetExpression) const = 0;
};