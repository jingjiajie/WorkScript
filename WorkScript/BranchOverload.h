#pragma once
#include "Overload.h"
#include "OverloadBranch.h"

namespace WorkScript {
	class BranchOverload : public Overload {
	public:
		virtual ~BranchOverload();

		inline BranchOverload(Function *func, const std::vector<Parameter*> &params, Type *returnType)
			: Overload(func, params, returnType) {}

		virtual GenerateResult generateLLVMIR(GenerateContext *context) override;

		inline OverloadBranch * getBranch(size_t index)
		{
			return this->branches[index];
		}

		inline void addBranch(OverloadBranch *branch)
		{
			this->branches.push_back(branch);
		}
	private:
		std::vector<OverloadBranch*> branches;
	};
}