#pragma once
#include "StackFrame.h"
class CallStack
{
public:
	const size_t MAX_CALL_STACK_DEPTH = 128;

	inline CallStack()
	{
		this->frames = new StackFrame*[MAX_CALL_STACK_DEPTH];
	}

	inline ~CallStack() 
	{
		delete[]this->frames;
	}

	inline StackFrame * newStackFrame(StackFrame *baseFrame, const size_t &localVariableCount)
	{
		if (this->frameCount >= this->MAX_CALL_STACK_DEPTH) {
			//TODO StackOverflowException
			throw L"Õ»Òç³ö";
		}
		auto newFrame = new StackFrame(baseFrame, localVariableCount);
		this->frames[this->frameCount] = newFrame;
		++this->frameCount;
		return newFrame;
	}

	inline void popStackFrame()
	{
		delete this->frames[--this->frameCount];
	}

	inline void clearStackFrame()
	{
		for (size_t i = 0; i < frameCount; ++i)
		{
			delete this->frames[i];
		}
	}

	inline size_t resetStackFrameLocalVariables(const size_t &frameID, const size_t &localVariableCount)
	{
		this->frames[frameID]->resetLocalVariableCount(localVariableCount);
	}

protected:
	StackFrame * *frames = nullptr;
	size_t frameCount = 0;
};