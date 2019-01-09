#pragma once
#include "Function.h"
#include <memory>

namespace WorkScript {
	class FunctionBranch;

	class BranchFunction : public Function {
	public:
		using Function::Function;

		~BranchFunction();

		virtual Type *getReturnType(InstantializeContext *instCtx) override;
		virtual GenerateResult generateLLVMIR(GenerateContext *context) override;

		size_t addBranch(FunctionBranch *branch);
		size_t getBranchCount() const { return this->branches.size(); }
	private:
		std::vector<FunctionBranch*> branches;
	};
}