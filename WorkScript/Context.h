#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <functional>

class TermExpression;
class TypeExpression;
class FunctionExpression;
class FunctionInvocationExpression;
class Expression;

class Context
{
public:
	Context(size_t localVariableCount);
	Context(Context *baseContext, size_t localVariableCount);
	virtual ~Context();

	void addType(const std::shared_ptr<TypeExpression>&);
	const std::shared_ptr<TypeExpression> findType(const std::string &typeName,bool isGenericType, const std::vector<std::shared_ptr<TypeExpression>> &genericTypes = std::vector<std::shared_ptr<TypeExpression>>()) const;

	Context * getBaseContext() const;
	void setBaseContext(Context *const);

	const std::shared_ptr<TermExpression> getCurrentExpression() const;
	void setCurrentExpression(const std::shared_ptr<TermExpression> &);

	const std::shared_ptr<TermExpression> getLocalVariable(size_t offset) const;
	void setLocalVariable(size_t offset, const std::shared_ptr<TermExpression> &value);
protected:
	Context * baseContext = nullptr;
	std::vector<std::shared_ptr<TypeExpression>> types;
	std::shared_ptr<TermExpression> *localVariables;
	std::shared_ptr<TermExpression> currentExpression;
};