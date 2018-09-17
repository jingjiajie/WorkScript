#pragma once
#include "Expression.h"
#include "StringExpression.h"
class NumberExpression;

class BinaryOperatorExpression :
	public Expression
{
public:
	inline BinaryOperatorExpression() 
	{
		
	}

	inline BinaryOperatorExpression(const Pointer<Expression> &left, const Pointer<Expression> &right)
	{
		this->setLeftExpression(left);
		this->setRightExpression(right);
	}

	virtual ~BinaryOperatorExpression();

	virtual bool equals(Context *const &context, const Pointer<Expression> &) const override;
	virtual void link(LinkContext *const& context) override;

	inline const Pointer<Expression> getLeftExpression() const
	{
		return this->leftExpression;
	}

	inline void setLeftExpression(const Pointer<Expression> &left)
	{
		this->leftExpression = left;
	}
	inline const Pointer<Expression> getRightExpression() const
	{
		return this->rightExpression;
	}

	inline void setRightExpression(const Pointer<Expression> &right)
	{
		this->rightExpression = right;
	}
protected:
	Pointer<Expression> leftExpression;
	Pointer<Expression> rightExpression;

	inline const Pointer<StringExpression> toString(Context *const &context, const Pointer<StringExpression> &middleStr)
	{
		Pointer<StringExpression> left =  this->leftExpression->toString(context);
		Pointer<StringExpression> right =  this->rightExpression->toString(context);
		Pointer<StringExpression> exprs[] = { left,middleStr,right };
		auto result = StringExpression::combine(exprs, 3);
		return result;
	}
};

