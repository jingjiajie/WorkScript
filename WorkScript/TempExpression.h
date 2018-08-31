#pragma once
#include "Expression.h"

template<typename TExpr = Expression>
class TempExpression
{
public:
	explicit inline TempExpression(const Expression *generator,Expression *const expr)
		:expression((TExpr *)expr),generator(generator)
	{
	}

	inline ~TempExpression()
	{
		this->release();
	}

	inline TExpr *const getExpression() const
	{
		return this->expression;
	}

	inline TExpr *const operator->()
	{
		return this->expression;
	}

	template<typename R>
	inline operator R*() 
	{
		return (R*)this->expression;
	}

	inline void setNoRelease()
	{
		this->noRelease = true;
	}

	inline void releaseTemp()
	{
		this->release();
		this->setNoRelease();
	}


	TempExpression(const TempExpression&) = delete;
	TempExpression & operator =(const TempExpression &) = delete;
private:
	TExpr * expression;
	const Expression *generator;
	bool noRelease = false;

	inline void release()
	{
		if (this->noRelease)return;
		if (this->expression == this->generator)return;
		this->expression->releaseTemp();
	}
};