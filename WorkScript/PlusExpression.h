#pragma once
#include <memory>
#include "TermExpression.h"

class NumberExpression;
class StringExpression;

class PlusExpression :
	public TermExpression
{
public:
	PlusExpression(Context *const &context);
	PlusExpression(Context *const &context, const std::shared_ptr<const Expression> &, const std::shared_ptr<const Expression> &);
	virtual ~PlusExpression();

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
	std::shared_ptr<const Expression> leftExpression;
	std::shared_ptr<const Expression> rightExpression;

private:
	std::shared_ptr<const NumberExpression> numberPlusNumber(const std::shared_ptr<const NumberExpression>&,const std::shared_ptr<const NumberExpression>&) const;
	std::shared_ptr<const StringExpression> exprPlusExpr(const std::shared_ptr<const Expression>&, const std::shared_ptr<const Expression>&) const;
};

