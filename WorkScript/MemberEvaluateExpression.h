//#pragma once
//#include <memory>
//#include "Expression.h"
//class MemberEvaluateExpression :
//	public Expression
//{
//public:
//	MemberEvaluateExpression(Expression* const &objExpr, Expression* const &memberExpr);
//	virtual ~MemberEvaluateExpression();
//
// virtual Expression* const evaluate(Context *const& context) override;
//	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
//	virtual bool equals(Context *const &context, Expression* const& targetExpression) const;
//	virtual TypeExpression* const getType(Context *const& context) const override;
//	virtual StringExpression *const toString(Context *const& context) override;
//
//	Expression* const getObjectExpression() const;
//	void setObjectExpression(Expression* const&);
//	Expression* const getMemberExpression() const;
//	void setMemberExpression(Expression* const&);
//
//protected:
//	Expression * objectExpression;
//	Expression * memberExpression;
//};
//
