#pragma once
#include "TermExpression.h"
#include "Context.h"

class TermExpression;

class ListExpression :
	public TermExpression
{
public:
	ListExpression();
	virtual ~ListExpression();

	virtual const std::shared_ptr<TypeExpression> getType() const;
	virtual const std::string toString() const;
	virtual void compile(CompileContext *context) override;

	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	virtual bool equals(const std::shared_ptr<TermExpression>&) const override;
	const std::vector<std::shared_ptr<TermExpression>> getItems() const;
	void setItems(const std::vector<std::shared_ptr<TermExpression>>& termExpressions);
private:
	std::vector<std::shared_ptr<TermExpression>> items;
};