#pragma once
#include <vector>
#include "ValueExpression.h"
class PolynomialExpression :
	public ValueExpression
{
public:
	PolynomialExpression(Context *const &context, const std::vector<std::shared_ptr<const Expression>> &subExpressions);
	virtual ~PolynomialExpression();

	const std::vector<std::shared_ptr<const Expression>>& getSubExpressions() const;
	void setSubExpressions(const std::vector<std::shared_ptr<const Expression>>&);

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;
	virtual const std::string toString() const;

protected:
	std::vector<std::shared_ptr<const Expression>> subExpressions;
};

