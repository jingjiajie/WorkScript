#pragma once
#include <string.h>
#include "Expression.h"
#include "VariableInfo.h"

class Context;

class VariableExpression :
	public Expression
{
public:
	inline VariableExpression(const char *const &name, const StorageLevel level = StorageLevel::TEMP)
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

	inline const char *const & getName() const 
	{
		return this->name;
	}

	inline void setName(const char *const &name) 
	{
		if (this->name)delete[]this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
protected:
	VariableInfo variableInfo;
	char * name = nullptr;
};

