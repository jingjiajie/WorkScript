#pragma once
#include <memory>
#include <functional>
#include "Expression.h"
class ExecuteCppCodeExpression :
	public Expression
{
public:
	inline ExecuteCppCodeExpression(const std::function<Expression* const(Context*)> &evaluateFunction, const StorageLevel level = StorageLevel::TEMP)
	{
		this->setStorageLevel(level);
		this->evaluateFunction = evaluateFunction;
	}
	virtual ~ExecuteCppCodeExpression();

 virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual bool equals(Context *const &context, Expression* const& targetExpression) const;
	virtual StringExpression *const toString(Context *const& context) override;
	virtual void compile(CompileContext *const& context) override;

protected:
	std::function<Expression* const(Context*)> evaluateFunction;
};

