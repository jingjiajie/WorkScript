#pragma once
#include "Expression.h"
#include "TempExpression.h"
#include "StringExpression.h"

class UnaryOperatorExpression :
	public Expression
{
public:

	inline UnaryOperatorExpression(const StorageLevel level = StorageLevel::TEMP)
	{
		this->setStorageLevel(level);
	}

	inline UnaryOperatorExpression(Expression* const &subExpression, const StorageLevel level = StorageLevel::TEMP)
	{
		this->setStorageLevel(level);
		this->setSubExpression(subExpression);
	}

	virtual ~UnaryOperatorExpression();

	virtual bool equals(Context *const &context, Expression* const&) const override;
	virtual void compile(CompileContext *const& context) override;

	inline Expression* const getSubExpression() const
	{
		return this->subExpression;
	}
	inline void setSubExpression(Expression* const &right)
	{
		this->subExpression = right;
	}
protected:
	Expression * subExpression;

	inline StringExpression * const toString(Context *const &context, StringExpression *const &signStr)
	{
		TempExpression<StringExpression> sub(this->subExpression, this->subExpression->toString(context));
		StringExpression *exprs[] = { signStr,sub };
		auto result = StringExpression::combine(exprs, 3);
		return result;
	}
};

