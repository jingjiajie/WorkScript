//#pragma once
//#include <memory>
//#include "TermExpression.h"
//class MemberEvaluateExpression :
//	public TermExpression
//{
//public:
//	MemberEvaluateExpression(const std::shared_ptr<TermExpression> &objExpr, const std::shared_ptr<TermExpression> &memberExpr);
//	virtual ~MemberEvaluateExpression();
//
// virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
//	//virtual bool match(const std::shared_ptr<TermExpression> &matchExpression, Context *context) const override;
//	virtual bool equals(const std::shared_ptr<TermExpression>& targetExpression) const;
//	virtual const std::shared_ptr<TypeExpression> getType() const override;
//	virtual const std::string toString() const override;
//
//	const std::shared_ptr<TermExpression> getObjectExpression() const;
//	void setObjectExpression(const std::shared_ptr<TermExpression>&);
//	const std::shared_ptr<TermExpression> getMemberExpression() const;
//	void setMemberExpression(const std::shared_ptr<TermExpression>&);
//
//protected:
//	std::shared_ptr<TermExpression> objectExpression;
//	std::shared_ptr<TermExpression> memberExpression;
//};
//
