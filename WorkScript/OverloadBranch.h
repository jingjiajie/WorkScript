#pragma once
#include <vector>
#include "Expression.h"

namespace WorkScript 
{
	class BranchOverload;

	class OverloadBranch 
	{
	public:
		inline OverloadBranch(BranchOverload *overload, Location loc, const std::vector<Expression*> &conds, const std::vector<Expression*> &codes)
		{
			this->overload = overload;
			this->location = loc;
			this->conditions = conds;
			this->codes = codes;
		}

		~OverloadBranch();

		virtual void bindSymbols();
		llvm::BasicBlock * generateBlock(GenerateContext *context, llvm::Function *llvmFunc, llvm::BasicBlock *falseBlock);
		inline Location getLocation() const { return this->location; };
	private:
		BranchOverload * overload;
		std::vector<Expression*> conditions;
		std::vector<Expression*> codes;
		Location location;
	};
}