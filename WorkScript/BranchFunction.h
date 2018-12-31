#pragma once
#include "Function.h"

namespace WorkScript {
	class FunctionBranch;

	class BranchFunction : public Function {
	public:
		virtual ~BranchFunction();

		inline BranchFunction(Program *program, const std::wstring &name, const std::vector<Type*> &paramTypes, Type *returnType)
			: Function(program, name, paramTypes, returnType) {}

		virtual Type *getReturnType(FunctionInstantializeContext *instCtx) override;
		virtual GenerateResult generateLLVMIR(GenerateContext *context) override;

		inline FunctionBranch * getBranch(size_t index) { return this->branches[index]; }
		void addBranch(FunctionBranch *branch);
	private:
		std::vector<FunctionBranch*> branches;
	};
}