#pragma once
#include <string>
#include "Expression.h"
#include "TypeExpression.h"

enum class Authority{
	PUBLIC,
	PRIVATE,
	PROTECTED
};

class TypeMemberExpression :
	public Expression
{
public:
	TypeMemberExpression(const std::shared_ptr<TypeExpression> &belongType,
		const Authority &authority,
		const std::shared_ptr<Expression> &expression);
	virtual ~TypeMemberExpression();

	virtual const std::shared_ptr<TypeExpression> getType() const override;
	//virtual bool equals(const std::shared_ptr<TermExpression>& targetExpression) const override;
	virtual const std::string toString() const override;
	virtual void compile(CompileContext *context) override;

	const std::shared_ptr<TypeExpression> getBelongType() const;
	void setBelongType(const std::shared_ptr<TypeExpression>&);
	const std::shared_ptr<Expression> getExpression() const;
	void setExpression(const std::shared_ptr<Expression>&);
	const Authority getAuthority() const;
	void setAuthority(const Authority &);
protected:
	bool canAccess(const std::shared_ptr<TypeExpression> &accessType) const;

	std::weak_ptr<TypeExpression> belongType;
	Authority authority;
	std::shared_ptr<Expression> expression;
};

