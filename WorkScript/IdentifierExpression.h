#pragma once
#include "TermExpression.h"

class IdentifierExpression :
	public TermExpression
{
public:
	IdentifierExpression(Context *const &context, const std::string& identifierName);
	virtual ~IdentifierExpression();

	const std::string& getIdentifierName() const;
	void setIdentifierName(const std::string& name);
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;
	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual const std::string toString() const override;
protected:
	std::string identifierName;
};