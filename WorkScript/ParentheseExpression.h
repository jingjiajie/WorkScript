#pragma once
#include <vector>
#include <memory>
#include "TermExpression.h"

class ParentheseExpression :
	public TermExpression
{
public:
	ParentheseExpression(Context *const &context,const std::shared_ptr<const Expression>&);
	virtual ~ParentheseExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;
	virtual const std::string toString() const override;

	const std::shared_ptr<const Expression>& getSubExpression() const;
	void setSubExpression(const std::shared_ptr<const Expression> &subExpressions);

private:
	std::shared_ptr<const Expression> subExpression;
};

