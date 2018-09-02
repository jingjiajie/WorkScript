//#pragma once
//#include <memory>
//#include "Expression.h"
//class MemberEvaluateExpression :
//	public Expression
//{
//public:
//	MemberEvaluateExpression(const Pointer<Expression> &objExpr, const Pointer<Expression> &memberExpr);
//	virtual ~MemberEvaluateExpression();
//
// virtual const Pointer<Expression> evaluate(Context *const& context) override;
//	//virtual bool match(const Pointer<Expression> &matchExpression, Context *const& context) const override;
//	virtual bool equals(Context *const &context, const Pointer<Expression> & targetExpression) const;
//	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
//	virtual const Pointer<StringExpression> toString(Context *const& context) override;
//
//	const Pointer<Expression> getObjectExpression() const;
//	void setObjectExpression(const Pointer<Expression> &);
//	const Pointer<Expression> getMemberExpression() const;
//	void setMemberExpression(const Pointer<Expression> &);
//
//protected:
//	Pointer<Expression>  objectExpression;
//	Pointer<Expression>  memberExpression;
//};
//
