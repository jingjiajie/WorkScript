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
	TypeMemberExpression(Context *const &context,
		const std::shared_ptr<const TypeExpression> &belongType,
		const Authority &authority,
		const std::shared_ptr<const Expression> &expression);
	virtual ~TypeMemberExpression();

	virtual const std::shared_ptr<const Expression> evaluate(const ExpressionBind &) const override;
	virtual bool match(const std::shared_ptr<const Expression> &matchExpression, ExpressionBind *outExpressionBind) const override;
	virtual bool equals(const std::shared_ptr<const Expression> &) const override;
	virtual const std::shared_ptr<const TypeExpression> getType() const override;
	virtual const std::string toString() const override;

	const std::shared_ptr<const TypeExpression> getBelongType() const;
	void setBelongType(const std::shared_ptr<const TypeExpression>&);
	const std::shared_ptr<const Expression> getExpression() const;
	void setExpression(const std::shared_ptr<const Expression>&);
	const Authority getAuthority() const;
	void setAuthority(const Authority &);
protected:
	bool canAccess(const std::shared_ptr<const TypeExpression> &accessType) const;

	std::shared_ptr<const TypeExpression> belongType;
	Authority authority;
	std::shared_ptr<const Expression> expression;
};

