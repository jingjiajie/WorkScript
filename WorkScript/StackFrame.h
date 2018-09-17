#pragma once
#include "Pointer.h"
#include "WorkScriptException.h"
#include <string>

class Expression;

class StackFrame
{
public:
	inline StackFrame(StackFrame *base, BLOCK_ID block, size_t localVariableCount = 0)
	{
		this->setBlockID(block);
		this->setBaseStackFrame(base);
		this->resetLocalVariableCount(localVariableCount);
	}

	inline ~StackFrame()
	{
		if (this->localVariables) delete[]this->localVariables;
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

	StackFrame * const getBaseStackFrame(BLOCK_ID block)
	{
		auto target = this;
		while (target) {
			if (target->block == block)return target;
			else target = target->baseStackFrame;
		}
		throw std::move(WorkScriptException((std::wstring(L"ÄÚ²¿´íÎó£ºÎ´ÕÒµ½Õ»Ö¡£º") + std::to_wstring(block)).c_str()));
	}

	inline StackFrame *getBaseStackFrame()const 
	{
		return this->baseStackFrame;
	}

	inline void setBaseStackFrame(StackFrame *base)
	{
		this->baseStackFrame = base;
	}

	inline void setBlockID(BLOCK_ID block) {
		this->block = block;
	}

	inline void resetLocalVariableCount(const size_t &count)
	{
		if (this->localVariableCount >= count) {
			this->localVariableCount = count;
			for (size_t i = 0; i < this->localVariableCount; ++i) {
				this->localVariables[i] = nullptr;
			}
		}
		else {
			if (this->localVariables) delete[]this->localVariables;
			this->localVariables = new Pointer<Expression>[count];
			this->localVariableCount = count;
		}
	}

protected:
	StackFrame *baseStackFrame;
	BLOCK_ID block = 0;
	Pointer<Expression> *localVariables = nullptr;
	size_t localVariableCount = 0;
};