#pragma once
#include <vector>
#include "Expression.h"

namespace WorkScript 
{
	class OverloadBranch 
	{
	public:
		inline OverloadBranch(const std::vector<Expression*> &conds, const std::vector<Expression*> &codes)
		{
			this->setConditions(conds);
			this->setCodes(codes);
		}

		llvm::BasicBlock * generateBlock(GenerateContext *context, llvm::BasicBlock *falseBlock, llvm::BasicBlock *mergeBlock);

		void setConditions(const std::vector<Expression*> &conds)
		{
			this->conditions = conds;
		}

		void setCodes(const std::vector<Expression*> codes)
		{
			this->codes = codes;
		}
	private:
		std::vector<Expression*> conditions;
		std::vector<Expression*> codes;
	};
}