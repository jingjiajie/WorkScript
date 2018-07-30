#pragma once
#include <memory>
#include "TermExpression.h"
#include "TypeExpression.h"
#include "BooleanExpression.h"
#include "NumberExpression.h"

class GreaterThanExpression :
	public TermExpression
{
public:
	GreaterThanExpression(Context *const &context, const std::shared_ptr<const Expression> &, const std::shared_ptr<const Expression> &);
	virtual ~GreaterThanExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;
	virtual const std::string toString() const override;

	const std::shared_ptr<const Expression> getLeftExpression() const;
	void setLeftExpression(const std::shared_ptr<const Expression>&);
	const std::shared_ptr<const Expression> getRightExpression() const;
	void setRightExpression(const std::shared_ptr<const Expression>&);
protected:
	const std::shared_ptr<const BooleanExpression> numberGreaterThanNumber(const std::shared_ptr<const NumberExpression>&, const std::shared_ptr<const NumberExpression>&)const;

	std::shared_ptr<const Expression> leftExpression, rightExpression;
	std::shared_ptr<const TypeExpression> type;
};