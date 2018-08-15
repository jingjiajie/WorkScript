#pragma once
#include "TermExpression.h"
#include <memory>

class BinaryTermExpression :
	public TermExpression
{
public:
	BinaryTermExpression();
	virtual ~BinaryTermExpression();

	virtual bool equals(const std::shared_ptr<TermExpression>&) const override;
	virtual void compile(CompileContext *context) override;

	const std::shared_ptr<TermExpression> getLeftExpression() const;
	void setLeftExpression(const std::shared_ptr<TermExpression>&);
	const std::shared_ptr<TermExpression> getRightExpression() const;
	void setRightExpression(const std::shared_ptr<TermExpression>&);
protected:
	std::shared_ptr<TermExpression> leftExpression;
	std::shared_ptr<TermExpression> rightExpression;
};

