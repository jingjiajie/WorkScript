#include "stdafx.h"
#include "BranchOverload.h"

WorkScript::BranchOverload::~BranchOverload()
{
	for (OverloadBranch *br : this->branches)delete br;
}

GenerateResult WorkScript::BranchOverload::generateIR(GenerateContext * context)
{
	llvm::Function *func = this->makeLLVMFunction(context);
	llvm::BasicBlock *entry = llvm::BasicBlock::Create(*context->getLLVMContext(), "entry", func);
	llvm::BasicBlock *mergeBlock = llvm::BasicBlock::Create(*context->getLLVMContext(), "merge", func);
	auto builder = context->getIRBuilder();
	builder->SetInsertPoint(entry);
	size_t branchCount = this->branches.size();
	llvm::BasicBlock *curFalseBlock = mergeBlock;
	for (size_t i = 0; i < this->branches.size(); ++i)
	{
		builder->SetInsertPoint(entry);
		curFalseBlock = this->branches[branchCount - i]->generateBlock(context, curFalseBlock, mergeBlock);
	}
	llvm::verifyFunction(*func);
	return (llvm::Value*)func;
}
