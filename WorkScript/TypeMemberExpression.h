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
//	TypeMemberExpression(const Pointer<TypeExpression> &belongType,
//		const Authority &authority,
//		const Pointer<Expression> &expression);
//	virtual ~TypeMemberExpression();
//
//	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
//	//virtual bool equals(const Pointer<Expression> & targetExpression) const override;
//	virtual const Pointer<StringExpression> toString(Context *const& context) override;
//	virtual void link(LinkContext *const& context) override;
//
//	const Pointer<TypeExpression> getBelongType() const;
//	void setBelongType(const Pointer<TypeExpression> &);
//	const Pointer<Expression> getExpression() const;
//	void setExpression(const Pointer<Expression> &);
//	const Authority getAuthority() const;
//	void setAuthority(const Authority &);
//protected:
//	bool canAccess(Context *const &context, const Pointer<TypeExpression> &accessType) const;
//
//	Pointer<TypeExpression> belongType;
//	Authority authority;
//	Pointer<Expression>  expression;
//};
//
