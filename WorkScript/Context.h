#pragma once
#include "Expression.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

class CallStack;
class StackFrame;
class TypeExpression;
class FunctionExpression;
class FunctionInvocationExpression;
class Expression;
class Program;

class Context final
{
public:
	inline Context(CallStack *callStack,StackFrame *stackFrame)
	{
		this->setCallStack(callStack);
		this->setStackFrame(stackFrame);
	}

	inline ~Context()
	{
	}

	inline const bool getAssignLeft() const
	{
		return this->assignLeft;
	}

	inline void setAssignLeft(const bool assignLeft)
	{
		this->assignLeft = assignLeft;
	}

	inline CallStack *getCallStack()const
	{
		return this->callStack;
	}

	inline void setCallStack(CallStack *callStack)
	{
		this->callStack = callStack;
	}

	inline StackFrame *getStackFrame() const
	{
		return this->stackFrame;
	}

	inline void setStackFrame(StackFrame *stackFrame)
	{
		this->stackFrame = stackFrame;
	}

protected:
	bool assignLeft = false;
	CallStack *callStack;
	StackFrame *stackFrame;
};