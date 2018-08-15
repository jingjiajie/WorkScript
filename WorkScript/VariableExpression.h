#pragma once
#include "TermExpression.h"
#include "VariableInfo.h"

class Context;

class VariableExpression :
	public TermExpression
{
public:
	VariableExpression(const std::string& identifierName);
	virtual ~VariableExpression();

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual bool equals(const std::shared_ptr<TermExpression>& targetExpression) const override;
	virtual const std::string toString() const override;
	virtual void compile(CompileContext *context) override;

	const std::string getName() const;
	void setName(const std::string &name);

	const VariableInfo getVariableInfo() const;
	void setVariableInfo(const VariableInfo &info);
protected:
	std::string name;
	VariableInfo variableInfo;
};

