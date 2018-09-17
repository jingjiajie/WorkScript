#pragma once
#include <memory>
#include <functional>
#include "Expression.h"
class ExecuteCppCodeExpression :
	public Expression
{
public:
	inline ExecuteCppCodeExpression(const std::function<const Pointer<Expression>(Context*)> &evaluateFunction)
	{
		this->evaluateFunction = evaluateFunction;
	}
	virtual ~ExecuteCppCodeExpression();

 virtual const Pointer<Expression> evaluate(Context *const& context) override;
	//virtual bool match(const Pointer<Expression> &matchExpression, Context *const& context) const override;
	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual bool equals(Context *const &context, const Pointer<Expression> & targetExpression) const;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;
	virtual void link(LinkContext *const& context) override;

protected:
	std::function<const Pointer<Expression>(Context*)> evaluateFunction;
};

