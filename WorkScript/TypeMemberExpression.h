//#pragma once
//#include <string>
//#include "Expression.h"
//#include "TypeExpression.h"
//
//enum class Authority{
//	PUBLIC,
//	PRIVATE,
//	PROTECTED
//};
//
//class TypeMemberExpression :
//	public Expression
//{
//public:
//	TypeMemberExpression(TypeExpression* const &belongType,
//		const Authority &authority,
//		Expression* const &expression);
//	virtual ~TypeMemberExpression();
//
//	virtual TypeExpression* const getType(Context *const& context) const override;
//	//virtual bool equals(Expression* const& targetExpression) const override;
//	virtual StringExpression *const toString(Context *const& context) override;
//	virtual void compile(CompileContext *const& context) override;
//
//	TypeExpression* const getBelongType() const;
//	void setBelongType(TypeExpression* const&);
//	Expression* const getExpression() const;
//	void setExpression(Expression* const&);
//	const Authority getAuthority() const;
//	void setAuthority(const Authority &);
//protected:
//	bool canAccess(Context *const &context, TypeExpression* const &accessType) const;
//
//	TypeExpression* belongType;
//	Authority authority;
//	Expression * expression;
//};
//
