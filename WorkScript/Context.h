#pragma once
#include "Expression.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

class TypeExpression;
class FunctionExpression;
class FunctionInvocationExpression;
class Expression;
class Program;

class Context final
{
public:
	inline Context(Program *p, size_t maxLocalVariableCount = 0)
		:program(p)
	{
		this->releaseAndResetLocalVariableCount(maxLocalVariableCount);
	}

	inline Context(Context *base, size_t maxLocalVariableCount = 0)
		:baseContext(base),program(base->program)
	{
		this->releaseAndResetLocalVariableCount(maxLocalVariableCount);
	}

	inline ~Context()
	{
		for (size_t i = 0; i < this->maxLocalVariableCount; ++i) {
			if (this->localVariables[i]) this->localVariables[i]->releaseLocal();
		}
		delete[]this->localVariables;
	}

	inline Context * const& getBaseContext() const
	{
		return this->baseContext;
	}

	void setBaseContext(Context *const ctx)
	{
		this->baseContext = ctx;
	}

	inline Expression* const getCurrentExpression() const
	{
		if (this->baseContext != nullptr) {
			return this->baseContext->getCurrentExpression();
		}
		else {
			return this->currentExpression;
		}
	}

	inline void setCurrentExpression(Expression* const expr)
	{
		if (this->baseContext != nullptr) {
			this->baseContext->setCurrentExpression(expr);
		}
		else {
			this->currentExpression = expr;
		}
	}

	inline void release()
	{
		delete this;
	}

	inline Expression* const getLocalVariable(const size_t &offset) const {
		return this->localVariables[offset];
	}

	inline Expression **const getLocalVariableAddress(const size_t &offset) const {
		return &this->localVariables[offset];
	}

	inline void setLocalVariable(size_t offset, Expression* const &value)
	{
		value->upgradeStorageLevel(StorageLevel::LOCAL);
		this->localVariables[offset] = value;
	}

	inline void releaseAndResetLocalVariableCount(const size_t &count)
	{
		for (size_t i = 0; i < this->maxLocalVariableCount; ++i)
		{
			if (this->localVariables[i]) {
				this->localVariables[i]->releaseLocal();
			}
		}
		if (this->maxLocalVariableCount >= count) {
			this->maxLocalVariableCount = count;
			for (size_t i = 0; i < count; ++i) {
				this->localVariables[i] = nullptr;
			}
		}
		else {
			if(this->localVariables) delete[]this->localVariables;
			this->localVariables = new Expression*[count]();
			this->maxLocalVariableCount = count;
		}
	}

	inline Program * const getProgram() const {
		return this->program;
	}

	inline const bool getAssignLeft() const
	{
		return this->assignLeft;
	}

	inline void setAssignLeft(const bool assignLeft)
	{
		this->assignLeft = assignLeft;
	}

protected:
	Context * baseContext = nullptr;
	Program *program = nullptr;
	Expression **localVariables = nullptr;
	Expression * currentExpression;
	size_t maxLocalVariableCount = 0;
	bool assignLeft = false;
};