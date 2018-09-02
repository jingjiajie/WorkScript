#pragma once
#include "BinaryOperatorExpression.h"

class BooleanExpression;
class DoubleExpression;
class VariableExpression;
class NumberExpression;

class BinaryCompareExpression :
	public BinaryOperatorExpression
{
public:
	inline BinaryCompareExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
		:BinaryOperatorExpression(left, right)
	{

	}

	inline BinaryCompareExpression()
		: BinaryOperatorExpression()
	{

	}
	virtual ~BinaryCompareExpression();

	virtual const Pointer<Expression> evaluate(Context *const& context) override;
	
	inline const Pointer<VariableExpression> getLeftVariable() const 
	{
		if (this->leftExpression->getType(nullptr)->equals(nullptr, TypeExpression::VARIABLE_EXPRESSION)) {
			return (Pointer<VariableExpression>&)this->leftExpression;
		}
		else {
			return nullptr;
		}
	}
protected:
	virtual const Pointer<BooleanExpression> numberCompareNumber(Context *context, const Pointer<NumberExpression> &left, const Pointer<NumberExpression> &right)const = 0;
	virtual const Pointer<BooleanExpression> expressionCompareExpression(Context *context, const Pointer<Expression> &left, const Pointer<Expression> &right)const;
};

