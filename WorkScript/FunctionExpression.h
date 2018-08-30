#pragma once
#include <vector>
#include <string.h>
#include <wchar.h>
#include "Expression.h"
#include "TypeExpression.h"

class FunctionInvocationExpression;
class VariableExpression;
class ParameterExpression;
class Context;

class ParameterInfo
{
public:
	inline ParameterInfo() {}

	inline ParameterInfo(const wchar_t *const &name) {
		this->setParameterName(name);
	}

	inline ParameterInfo(const wchar_t *const &name,Expression *const &defaultValue) {
		this->setParameterName(name);
		this->setDefaultValue(defaultValue);
	}

	inline ParameterInfo(const wchar_t *const &name, const size_t &offset) {
		this->setParameterName(name);
		this->setOffset(offset);
	}

	inline ~ParameterInfo() {
		if (this->parameterName) {
			delete[]this->parameterName;
		}
	}

	inline const wchar_t *const getParameterName()const {
		return this->parameterName;
	}

	inline void setParameterName(const wchar_t *const &name) {
		if (this->parameterName) {
			delete[]this->parameterName;
		}
		size_t len = wcslen(name);
		this->parameterName = new wchar_t[len + 1];
		wcscpy(this->parameterName, name);
		this->parameterName[len] = 0;
	}

	inline const size_t getOffset()const {
		return this->offset;
	}

	inline void setOffset(const size_t &offset) {
		this->offset = offset;
	}

	inline Expression *const getDefaultValue()const	{
		return this->defaultValue;
	}

	inline void setDefaultValue(Expression *const &value) {
		this->defaultValue = value;
	}

private:
	wchar_t *parameterName = nullptr;
	Expression *defaultValue = nullptr;
	size_t offset;
};


class Overload {
public:
	inline ~Overload()
	{
		if (this->parameters) {
			delete[]this->parameters;
		}

		if (this->constraints) {
			for (size_t i = 0; i < this->constraintCount; ++i) {
				this->constraints[i]->releaseLiteral();
			}
			delete[]this->constraints;
		}

		for (size_t i = 0; i < this->implementCount; ++i)
		{
			if (this->implements[i]) this->implements[i]->releaseLiteral();
		}
		delete[]this->implements;
	}

	virtual bool match(ParameterExpression* const &params, Context *const& context) const;
	virtual Expression* const invoke(Context *const& context) const;
	virtual void compile(CompileContext *const& context);

	inline const ParameterInfo *const getParameterInfos() const
	{
		return this->parameters;
	}

	inline void setParameterInfos(ParameterInfo *const &params, size_t count)
	{
		this->parameterCount = count;
		if (this->parameters) {
			delete[]this->parameters;
		}
		this->parameters = params;
	}

	inline Expression **const getConstraints() const
	{
		return this->constraints;
	}

	inline void setConstraints(Expression **const &constraints, const size_t &count)
	{
		this->constraintCount = count;
		this->constraints = constraints;
	}

	inline const bool getAllowLastMatchRest()const
	{
		return this->allowLastMatchRest;
	}

	inline void setAllowLastMatchRest(const bool& allowLastMatchRest)
	{
		this->allowLastMatchRest = allowLastMatchRest;
	}

	inline Expression** const getImplements() const
	{
		return this->implements;
	}

	inline void setImplements(Expression** const &impls, const size_t &count)
	{
		this->implementCount = count;
		this->implements = impls;
	}

	inline void setImplement(Expression *impl)
	{
		this->implementCount = 1;
		this->implements = new Expression*[1]{ impl };
	}

	inline const size_t getLocalVariableCount() const
	{
		return this->localVariableCount;
	}
	inline void setLocalVariableCount(const size_t &count)
	{
		this->localVariableCount = count;
	}

protected:
	bool allowLastMatchRest = true;
	ParameterInfo *parameters = nullptr;
	size_t parameterCount = 0;

	Expression **constraints = nullptr;
	size_t constraintCount = 0;
	Expression **implements = nullptr;
	size_t implementCount = 0;

	size_t localVariableCount = 0; //编译时存储局部变量个数，用于运行时分配局部变量空间
};


class FunctionExpression :
	public Expression
{
public:
	inline FunctionExpression(const StorageLevel level = StorageLevel::TEMP)
	{
		this->setStorageLevel(level);
	}
	virtual ~FunctionExpression();

	virtual TypeExpression* const getType(Context *const& context) const override;
	virtual Expression* const evaluate(Context *const& context) override;
	virtual bool equals(Context *const &context, Expression* const& targetExpression) const;
	virtual StringExpression *const toString(Context *const& context) override;
	virtual void compile(CompileContext *const& context) override;

	virtual Expression* const invoke(ParameterExpression *const &params) const;

	inline const wchar_t *const getName()const
	{
		return name;
	}

	inline void setName(const wchar_t *const &funcName)
	{
		if (this->name)delete[]this->name;
		this->name = new wchar_t[wcslen(funcName) + 1];
		wcscpy(this->name, funcName);
	}

	inline 	const std::vector<Overload *> getOverloads()const
	{
		return this->overloads;
	}

	inline void addOverload(Overload* const &overload)
	{
		this->overloads.push_back(overload);
	}

protected:
	Context * declareContext;
	wchar_t *name;
	VariableInfo functionVariableInfo;
	std::vector<Overload *> overloads;
	VariableInfo baseFunctionVariableInfo;
};
