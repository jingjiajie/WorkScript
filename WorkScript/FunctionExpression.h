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

		inline const std::vector<std::string> getParameterNames() const
		{
			return this->parameterNames;
		}

		inline void setParameterNames(const std::vector<std::string>& parameters)
		{
			this->parameterCount = parameters.size();
			this->parameterNames = parameters;
		}

		inline Expression **const getConstraints() const
		{
			return this->constraints;
		}

		inline void setConstraints(Expression **const &constraints,const size_t &count)
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
			this->implements = new Expression*[1]{impl};
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
		std::vector<std::string> parameterNames;
		size_t *parameterLocalOffsets;
		size_t parameterCount;

		Expression **constraints;
		size_t constraintCount;
		Expression **implements;
		size_t implementCount;

		size_t localVariableCount = 0; //编译时存储局部变量个数，用于运行时分配局部变量空间
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
	char *name;
	VariableInfo functionVariableInfo;
	std::vector<Overload *> overloads;
	VariableInfo baseFunctionVariableInfo;
};

