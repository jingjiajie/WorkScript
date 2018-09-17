#pragma once
#include "Expression.h"
#include "StringExpression.h"

class UnaryOperatorExpression :
	public Expression
{
public:

	inline UnaryOperatorExpression()
	{
		
	}

	inline UnaryOperatorExpression(const Pointer<Expression> &subExpression)
	{
		
		this->setSubExpression(subExpression);
	}

	virtual ~UnaryOperatorExpression();

	virtual bool equals(Context *const &context, const Pointer<Expression> &) const override;
	virtual void link(LinkContext *const& context) override;

	inline const Pointer<Expression> getSubExpression() const
	{
		return this->subExpression;
	}
	inline void setSubExpression(const Pointer<Expression> &right)
	{
		this->subExpression = right;
	}
protected:
	Pointer<Expression>  subExpression;

	inline const Pointer<StringExpression> toString(Context *const &context, const Pointer<StringExpression> &signStr)
	{
		Pointer<StringExpression> sub =  this->subExpression->toString(context);
		Pointer<StringExpression>exprs[] = { signStr,sub };
		auto result = StringExpression::combine(exprs, 3);
		return result;
	}
};

