#pragma once
#include <vector>
#include <string.h>
#include "Expression.h"
#include "TypeExpression.h"

class FunctionInvocationExpression;
class VariableExpression;
class ParameterExpression;
class Context;

class FunctionExpression :
	public Expression
{
public:
	class Overload {
	public:
		~Overload();
		virtual bool match(ParameterExpression* const &params, Context *const& context) const;
		virtual Expression* const invoke(Context *const& context) const;
		virtual void compile(CompileContext *const& context);

		const std::vector<std::string> getParameterNames() const;
		void setParameterNames(const std::vector<std::string>& parameters);
		Expression **const getConstraints() const;
		void setConstraints(Expression **const &constraints, size_t count);
		const bool getAllowLastMatchRest()const;
		void setAllowLastMatchRest(const bool& allowLastMatchRest);
		Expression* const getImplement() const;
		void setImplement(Expression* const &implement);
		const size_t getLocalVariableCount() const;
		void setLocalVariableCount(const size_t &count);

	protected:
		bool allowLastMatchRest = true;
		std::vector<std::string> parameterNames;
		size_t *parameterLocalOffsets;
		size_t parameterCount;

		Expression **constraints;
		size_t constraintCount;
		Expression *implement;

		size_t localVariableCount = 0;
	};

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

	inline const char *const getName()const
	{
		return name;
	}

	inline void setName(const char *const &funcName) 
	{
		if (this->name)delete[]this->name;
		this->name = new char[strlen(funcName) + 1];
		strcpy(this->name,funcName);
	}

	const std::vector<Overload *> getOverloads()const;
	void addOverload(Overload* const &overload);

protected:
	Context * declareContext;
	char *name;
	VariableInfo functionVariableInfo;
	std::vector<Overload *> overloads;
	VariableInfo baseFunctionVariableInfo;
};

