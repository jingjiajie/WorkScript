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
		this->resetLocalVariableCount(maxLocalVariableCount);
	}

	inline Context(Context *base, size_t maxLocalVariableCount = 0)
		:baseContext(base),program(base->program)
	{
		this->depth = base->depth + 1;
		this->resetLocalVariableCount(maxLocalVariableCount);
	}

	inline ~Context()
	{
		delete[]this->localVariables;
	}

	Context *const getBaseContext(int depth);

	inline Context * const& getBaseContext() const
	{
		return this->baseContext;
	}

	void setBaseContext(Context *const ctx)
	{
		this->baseContext = ctx;
	}

	//inline const Pointer<Expression> getCurrentExpression() const
	//{
	//	if (this->baseContext != nullptr) {
	//		return this->baseContext->getCurrentExpression();
	//	}
	//	else {
	//		return this->currentExpression;
	//	}
	//}

	//inline void setCurrentExpression(const Pointer<Expression> expr)
	//{
	//	if (this->baseContext != nullptr) {
	//		this->baseContext->setCurrentExpression(expr);
	//	}
	//	else {
	//		this->currentExpression = expr;
	//	}
	//}

	inline void release()
	{
		delete this;
	}

	inline const Pointer<Expression> getLocalVariable(const size_t &offset) const {
		return this->localVariables[offset];
	}
	   
	inline Pointer<Expression> *const getLocalVariableAddress(const size_t &offset) const {
		return &this->localVariables[offset];
	}

	inline void setLocalVariable(size_t offset, const Pointer<Expression> &value)
	{
		this->localVariables[offset] = value;
	}

	inline void resetLocalVariableCount(const size_t &count)
	{
		if (this->maxLocalVariableCount >= count) {
			this->maxLocalVariableCount = count;
			for (size_t i = 0; i < this->maxLocalVariableCount; ++i) {
				this->localVariables[i] = nullptr;
			}
		}
		else {
			if(this->localVariables) delete[]this->localVariables;
			this->localVariables = new Pointer<Expression>[count];
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
	Context *baseContext = nullptr;
	Program *program = nullptr;
	Pointer<Expression> *localVariables = nullptr;
	size_t maxLocalVariableCount = 0;
	int depth = 0;
	bool assignLeft = false;
};