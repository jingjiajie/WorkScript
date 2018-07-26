#pragma once
#include "TermExpression.h"
class GetTypeExpression :
	public TermExpression
{
public:
	GetTypeExpression(Context *const &context, const std::shared_ptr<const Expression> &expression);
	virtual ~GetTypeExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;
	virtual const std::string toString() const override;

	const std::shared_ptr<const Expression> getExpression() const;
	void setExpression(const std::shared_ptr<const Expression>&);
protected:
	std::shared_ptr<const Expression> expression;
};

