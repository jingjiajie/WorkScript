#pragma once
#include <string.h>
#include <wchar.h>
#include "Expression.h"

class Context;

class VariableExpression :
	public Expression
{
public:
	inline VariableExpression(const wchar_t *const &name)
	{
		this->setName(name);
	}

	virtual ~VariableExpression();

	virtual const Pointer<Expression> evaluate(Context *const& context) override;
	//virtual bool match(const Pointer<Expression> &matchExpression, Context *const& context) const override;
	virtual const Pointer<TypeExpression> getType(Context *const& context) const override;
	virtual bool equals(Context *const &context, const Pointer<Expression> & targetExpression) const override;
	virtual const Pointer<StringExpression> toString(Context *const& context) override;
	virtual void link(LinkContext *const& context) override;

	inline const wchar_t *const & getName() const 
	{
		return this->name;
	}

	inline void setName(const wchar_t *const &name) 
	{
		if (this->name)delete[]this->name;
		this->name = new wchar_t[wcslen(name) + 1];
		wcscpy(this->name, name);
	}

	inline bool isVarargs()
	{
		return this->varargs;
	}

	inline void setVarargs(bool isVarargs)
	{
		this->varargs = isVarargs;
	}

	inline DOMAIN_ID getDomain() const {
		return this->domain;
	}

	inline void setDomain(DOMAIN_ID domain) {
		this->domain = domain;
	}

	inline DomainAccess getDomainAccess() const {
		return this->domainAccess;
	}

	inline void setDomainAccess(DomainAccess domainAccess) {
		this->domainAccess = domainAccess;
	}

	inline bool isDeclarable() const {
		return this->declarable;
	}

	inline void setDeclarable(bool declarable) {
		this->declarable = declarable;
	}
protected:
	wchar_t * name = nullptr;
	BLOCK_ID targetBlock = 0;
	size_t offset = 0;
	bool varargs = false;

	DOMAIN_ID domain;
	DomainAccess domainAccess = DomainAccess::PUBLIC;
	bool declarable = false; //可声明变量，如果具有此属性，则遇到该变量时可以创建声明。否则提示找不到符号
};
