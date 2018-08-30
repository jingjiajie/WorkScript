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
	inline VariableExpression(const wchar_t *const &name, const StorageLevel level = StorageLevel::TEMP)
	{
		this->setName(name);
		this->setStorageLevel(level);
	}

	virtual ~VariableExpression();

	virtual Expression* const evaluate(Context *const& context) override;
	//virtual bool match(Expression* const &matchExpression, Context *const& context) const override;
	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual bool equals(Context *const &context, Expression* const& targetExpression) const override;
	virtual StringExpression *const toString(Context *const& context) override;
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

