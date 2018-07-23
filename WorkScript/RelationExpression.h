#pragma once
#include "Expression.h"

class RelationExpression : public Expression
{
public:
	RelationExpression(Context *const &context, const std::shared_ptr<const Expression> &leftExpression, const std::shared_ptr<const Expression> &rightExpression);
	virtual ~RelationExpression();
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;

	void setLeftAndRightExpression(const std::shared_ptr<const Expression> &leftExpression, const std::shared_ptr<const Expression> &rightExpression);
	const std::shared_ptr<const Expression> & getLeftExpression() const;
	const std::shared_ptr<const Expression> & getRightExpression() const;
protected:
	std::shared_ptr<const Expression> leftExpression = nullptr;
	std::shared_ptr<const Expression> rightExpression = nullptr;
};