#pragma once
#include <vector>
#include "TermExpression.h"
#include "TypeExpression.h"

class FunctionInvocationExpression;
class VariableExpression;
class ListExpression;
class Context;

class FunctionExpression :
	public TermExpression
{
public:
	class Overload {
	public:
		virtual bool match(const std::shared_ptr<ListExpression> &params, Context *context) const;
		virtual const std::shared_ptr<TermExpression> invoke(Context *context) const;
		virtual void compile(CompileContext *context);

		const std::vector<std::string> getParameterNames() const;
		void setParameterNames(const std::vector<std::string>& parameters);
		const std::vector<std::shared_ptr<TermExpression>> getConstraints() const;
		void setConstraints(const std::vector<std::shared_ptr<TermExpression>> &constraints);
		const bool getAllowLastMatchRest()const;
		void setAllowLastMatchRest(const bool& allowLastMatchRest);
		const std::shared_ptr<TermExpression> getImplement() const;
		void setImplement(const std::shared_ptr<TermExpression> &implement);

	protected:
		bool allowLastMatchRest = true;
		std::vector<std::string> parameterNames;
		std::vector<size_t> parameterLocalOffsets;

		std::vector<std::shared_ptr<TermExpression>> constraints;
		std::shared_ptr<TermExpression> implement;
	};

	FunctionExpression();
	virtual ~FunctionExpression();

	virtual const std::shared_ptr<TypeExpression> getType() const override;
	virtual const std::shared_ptr<TermExpression> evaluate(Context *context) override;
	virtual bool equals(const std::shared_ptr<TermExpression>& targetExpression) const;
	virtual const std::string toString() const override;
	virtual void compile(CompileContext *context) override;

	virtual const std::shared_ptr<TermExpression> invoke(const std::shared_ptr<ListExpression> &params) const;

	const std::string getFunctionName()const;
	void setFunctionName(const std::string &funcName);
	const std::vector<std::shared_ptr<Overload>> getOverloads()const;
	void addOverload(const std::shared_ptr<Overload> &overload);

protected:
	Context * declareContext;
	std::string functionName;
	VariableInfo functionVariableInfo;
	std::vector<std::shared_ptr<Overload>> overloads;
	VariableInfo baseFunctionVariableInfo;
	size_t localVariableCount = 0;
};

