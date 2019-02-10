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
	inline GenerateResult() noexcept {}

	inline GenerateResult(llvm::Value *value, llvm::Value *value1 = nullptr) noexcept {
		this->setValue(value);
		this->setValue1(value1);
	}

	inline ~GenerateResult() noexcept = default;

	inline llvm::Value * getValue()const noexcept {
		return this->value;
	}

	inline void setValue(llvm::Value *value) noexcept {
		this->value = value;
	}

	inline llvm::Value * getValue1()const noexcept {
		return this->value1;
	}

	inline void setValue1(llvm::Value *value1) noexcept {
		this->value1 = value1;
	}
private:
	llvm::Value * value;
	llvm::Value * value1;
};

