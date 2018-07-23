#pragma once
#include <memory>
#include "PolynomialExpression.h"
class MemberEvaluateExpression :
	public PolynomialExpression
{
public:
	MemberEvaluateExpression(Context *const &context ,const std::shared_ptr<const Expression> &objExpr, const std::shared_ptr<const Expression> &memberExpr);
	virtual ~MemberEvaluateExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;

	const std::shared_ptr<const Expression> getObjectExpression() const;
	void setObjectExpression(const std::shared_ptr<const Expression>&);
	const std::shared_ptr<const Expression> getMemberExpression() const;
	void setMemberExpression(const std::shared_ptr<const Expression>&);

protected:
	std::shared_ptr<const Expression> objectExpression;
	std::shared_ptr<const Expression> memberExpression;
};

