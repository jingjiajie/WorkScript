#pragma once
#include <string>
#include <memory>
#include "PolynomialExpression.h"
class StringExpression :
	public PolynomialExpression
{
public:
	StringExpression(Context *const &context);
	StringExpression(Context *const &context,const std::string &value);
	virtual ~StringExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;

	const std::string getValue() const;
	void setValue(const std::string &value);
protected:
	std::string value;
};

