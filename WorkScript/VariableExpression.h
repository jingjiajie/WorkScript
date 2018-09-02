#pragma once
#include <string.h>
#include <wchar.h>
#include "Expression.h"
#include "VariableInfo.h"

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
	virtual void compile(CompileContext *const& context) override;

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
protected:
	VariableInfo variableInfo;
	wchar_t * name = nullptr;
};

