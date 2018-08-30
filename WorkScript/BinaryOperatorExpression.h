#pragma once
#include "Expression.h"
#include "StringExpression.h"
#include "TempExpression.h"

class BinaryOperatorExpression :
	public Expression
{
public:
	inline BinaryOperatorExpression(const StorageLevel level = StorageLevel::TEMP) 
	{
		this->setStorageLevel(level);
	}

	inline BinaryOperatorExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
	{
		this->setStorageLevel(level);
		this->setLeftExpression(left);
		this->setRightExpression(right);
	}

	virtual ~BinaryOperatorExpression();

	virtual bool equals(Context *const &context, Expression* const&) const override;
	virtual void compile(CompileContext *const& context) override;

	inline Expression* const getLeftExpression() const
	{
		return this->leftExpression;
	}
	inline Expression* const popLeftExpression()
	{
		auto expr = this->leftExpression;
		this->leftExpression = nullptr;
		return expr;
	}
	inline void setLeftExpression(Expression* const &left)
	{
		this->leftExpression = left;
	}
	inline Expression* const getRightExpression() const
	{
		return this->rightExpression;
	}
	inline Expression* const popRightExpression()
	{
		auto expr = this->rightExpression;
		this->rightExpression = nullptr;
		return expr;
	}
	inline void setRightExpression(Expression* const &right)
	{
		this->rightExpression = right;
	}
protected:
	Expression * leftExpression;
	Expression * rightExpression;

	inline StringExpression * const toString(Context *const &context, StringExpression *const &middleStr)
	{
		TempExpression<StringExpression> left(this->leftExpression, this->leftExpression->toString(context));
		TempExpression<StringExpression> right(this->rightExpression, this->rightExpression->toString(context));
		StringExpression *exprs[] = { left,middleStr,right };
		auto result = StringExpression::combine(exprs, 3);
		return result;
	}
};

