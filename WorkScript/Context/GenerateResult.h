#pragma once
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/Object/ObjectFile.h>
#include <llvm/Support/TargetSelect.h>

class GenerateResult
{
public:
	inline GenerateResult() {}

	inline GenerateResult(llvm::Value *value, llvm::Value *value1 = nullptr) {
		this->setValue(value);
		this->setValue1(value1);
	}

	inline ~GenerateResult() {}

	inline llvm::Value * getValue()const {
		return this->value;
	}

	inline void setValue(llvm::Value *value) {
		this->value = value;
	}

	inline llvm::Value * getValue1()const {
		return this->value1;
	}

	inline void setValue1(llvm::Value *value1) {
		this->value1 = value1;
	}
private:
	llvm::Value * value;
	llvm::Value * value1;
};

