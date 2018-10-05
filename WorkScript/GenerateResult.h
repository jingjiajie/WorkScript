#pragma once

class GenerateResult
{
public:
	inline GenerateResult(llvm::Value *value) {
		this->setValue(value);
	}

	inline ~GenerateResult() {}

	inline llvm::Value * getValue()const {
		return this->value;
	}

	inline void setValue(llvm::Value *value) {
		this->value = value;
	}
private:
	llvm::Value * value;
};

