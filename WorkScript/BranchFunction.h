#pragma once
#include "Function.h"
#include <memory>

namespace WorkScript {
	class FunctionBranch;

	class BranchFunction : public Function {
	public:
		inline BranchFunction(Program *program, const std::wstring &name, const std::vector<Type*> &paramTypes, Type *returnType)
			: Function(program, name, paramTypes, returnType) {}

		~BranchFunction();

		virtual Type *getReturnType(InstantializeContext *instCtx) override;
		virtual GenerateResult generateLLVMIR(GenerateContext *context) override;

		size_t addBranch(FunctionBranch *branch);
		size_t getBranchCount() const { return this->branches.size(); }
	private:
		std::vector<FunctionBranch*> branches;
	};
}