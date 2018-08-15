#pragma once
#include "TermExpression.h"
class BooleanExpression :
	public TermExpression
{
public:
	BooleanExpression();
	BooleanExpression(const bool &value);
	virtual ~BooleanExpression();

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual bool equals(const std::shared_ptr<TermExpression>& targetExpression) const override;
	virtual const std::string toString() const override;
	virtual void compile(CompileContext *context) override;

	const bool getValue() const;
	void setValue(const bool &value);
protected:
	bool value;

public:
	static std::shared_ptr<BooleanExpression> YES, NO;

};

