#pragma once
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/Object/ObjectFile.h>
#include <llvm/Support/TargetSelect.h>
#include <vector>

class GenerateResult
{
public:
	GenerateResult() noexcept {}

	GenerateResult(llvm::Value *value) noexcept {
		this->values.push_back(value);
	}

	GenerateResult(const std::vector<llvm::Value*> &values) noexcept
		: values(values){ }

	~GenerateResult() noexcept = default;

	llvm::Value * getValue()const noexcept {
		if(this->values.empty()) return nullptr;
		else return this->values[0];
	}

	std::vector<llvm::Value*> & getValues() noexcept{
		return this->values;
	}

	operator llvm::Value*(){
	    return this->getValue();
	}
private:
	std::vector<llvm::Value*> values;
};

