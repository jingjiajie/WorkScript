#pragma once
#include "Overload.h"
#include "OverloadBranch.h"

namespace WorkScript {
	class BranchOverload : public Overload {
	public:
		virtual ~BranchOverload();

		template<size_t paramCount>
		inline BranchOverload(Function *func, Parameter *const (&params)[paramCount], Type *returnType)
			: BranchOverload(func, params, returnType) {}

		virtual GenerateResult generateIR(GenerateContext *context);

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