#pragma once
#include "Expression.h"
#include "StringExpression.h"

class BinaryTermExpression :
	public Expression
{
public:
	inline BinaryTermExpression(const StorageLevel level = StorageLevel::TEMP) 
	{
		this->setStorageLevel(level);
	}

	inline BinaryTermExpression(Expression* const &left, Expression* const &right, const StorageLevel level = StorageLevel::TEMP)
	{
		this->setStorageLevel(level);
		this->setLeftExpression(left);
		this->setRightExpression(right);
	}

	virtual ~BinaryTermExpression();

	virtual bool equals(Context *const &context, Expression* const&) const override;
	virtual void compile(CompileContext *const& context) override;

	inline Expression* const getLeftExpression() const
	{
		return this->leftExpression;
	}
	inline void setLeftExpression(Expression* const &left)
	{
		this->leftExpression = left;
	}
	inline Expression* const getRightExpression() const
	{
		return this->rightExpression;
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
		auto left = this->leftExpression->toString(context);
		auto right = this->rightExpression->toString(context);
		StringExpression *exprs[] = { left,middleStr,right };
		auto result = StringExpression::combine(exprs, 3);
		left->releaseTemp();
		right->releaseTemp();
		return result;
	}
};

