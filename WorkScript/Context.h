#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <functional>

class Expression;
class TypeExpression;
class FunctionExpression;
class FunctionInvocationExpression;
class Expression;
class Program;

class Context
{
public:
	Context(Program *program,size_t localVariableCount);
	Context(Context *baseContext, size_t localVariableCount);
	virtual ~Context();

	//void addType(TypeExpression* const&);
	//TypeExpression* const findType(const std::string &typeName,bool isGenericType, const std::vector<TypeExpression *> &genericTypes = std::vector<TypeExpression *>());

	Context * const& getBaseContext() const;
	void setBaseContext(Context *const);

	Expression* const getCurrentExpression() const;
	void setCurrentExpression(Expression* const &);

	inline Expression* const getLocalVariable(size_t offset) const {
		return this->localVariables[offset];
	}

	inline void setLocalVariable(size_t offset, Expression* const &value) {
		this->localVariables[offset] = value;
	}

	inline Program * const getProgram() const {
		return this->program;
	}
protected:
	Context * baseContext = nullptr;
	Program *program = nullptr;
	//std::vector<TypeExpression *> types;
	Expression **localVariables;
	size_t localVariableCount = 0;
	Expression * currentExpression;
};