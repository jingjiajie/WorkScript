#pragma once
#include "Pointer.h"
#include "WorkScriptException.h"
#include <string>

class Expression;

class StackFrame
{
public:
	inline StackFrame(StackFrame *base, size_t maxLocalVariableCount = 0)
	{
		this->setBaseStackFrame(base);
		this->resetLocalVariableCount(maxLocalVariableCount);
	}

	inline ~StackFrame()
	{
		if(this->localVariables) delete[]this->localVariables;
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
			if (this->localVariables) delete[]this->localVariables;
			this->localVariables = new Pointer<Expression>[count];
			this->maxLocalVariableCount = count;
		}
	}

	StackFrame * const getBaseStackFrame(size_t depth)
	{
		if (depth > this->depth) {
			throw WorkScriptException((std::wstring(L"内部错误：getBaseStackFrame只能获取父级栈帧。当前深度：") + std::to_wstring(this->depth) + L"目标深度：" + std::to_wstring(depth)).c_str());
		}
		auto target = this;
		while (target) {
			if (target->depth == depth)break;
			else target = target->baseStackFrame;
		}
		return target;
	}

	inline StackFrame *getBaseStackFrame()const 
	{
		return this->baseStackFrame;
	}

	inline void setBaseStackFrame(StackFrame *base)
	{
		this->baseStackFrame = base;
		if (base)this->depth = base->depth + 1;
	}

	inline void increaseDepth()
	{
		++this->depth;
	}

	inline void decreaseDepth()
	{
		--this->depth;
	}

protected:
	StackFrame *baseStackFrame;
	size_t depth = 0;
	Pointer<Expression> *localVariables = nullptr;
	size_t maxLocalVariableCount = 0;
};