//#pragma once
//#include <memory>
//#include "Expression.h"
//class MemberEvaluateExpression :
//	public Expression
//{
//public:
//	MemberEvaluateExpression(Expression *objExpr, Expression *memberExpr);
//	virtual ~MemberEvaluateExpression();
//
// 
//	//virtual bool match(Expression *matchExpression, Context *const& context) const override;
//	virtual bool equals(Context *const &context, Expression * targetExpression) const;
//	virtual Type * getType() const override;
//	virtual std::wstring toString() override;
//
//	Expression * getObjectExpression() const;
//	void setObjectExpression(Expression *);
//	Expression * getMemberExpression() const;
//	void setMemberExpression(Expression *);
//
//protected:
//	Pointer<Expression>  objectExpression;
//	Pointer<Expression>  memberExpression;
//};
//
