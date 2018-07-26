#pragma once
#include "IdentifierExpression.h"
class VariableExpression :
	public IdentifierExpression
{
public:
	VariableExpression(Context *const &context, const std::string& identifierName);
	virtual ~VariableExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;
	virtual const std::string toString() const override;
};

