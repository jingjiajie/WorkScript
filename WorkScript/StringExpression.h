#pragma once
#include <string>
#include <memory>
#include "TermExpression.h"
class StringExpression :
	public TermExpression
{
public:
	StringExpression();
	StringExpression(const std::string &value);
	virtual ~StringExpression();

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
//	virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual bool equals(const std::shared_ptr<TermExpression>& targetExpression) const;
	virtual const std::string toString() const override;
	virtual void compile(CompileContext *context) override;

	const std::string getValue() const;
	void setValue(const std::string &value);
protected:
	std::string value;
};

