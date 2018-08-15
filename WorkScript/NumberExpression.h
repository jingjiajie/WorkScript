#pragma once
#include "TermExpression.h"
class NumberExpression :
	public TermExpression
{
public:
	NumberExpression();
	NumberExpression(const double &value);
	virtual ~NumberExpression();

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual bool equals(const std::shared_ptr<TermExpression>& targetExpression) const;
	virtual const std::string toString() const override;
	virtual void compile(CompileContext *context) override;

	const double getValue() const;
	void setValue(const double &value);
protected:
	double value;
};

