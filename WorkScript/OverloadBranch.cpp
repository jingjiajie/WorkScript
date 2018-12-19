#include "stdafx.h"
#include "OverloadBranch.h"

WorkScript::OverloadBranch::~OverloadBranch()
{
	for (auto expr : this->conditions) {
		delete expr;
	}
	for (auto expr : this->codes) {
		delete expr;
	}
}

llvm::BasicBlock * WorkScript::OverloadBranch::generateBlock(GenerateContext * context, llvm::Function *llvmFunc, llvm::BasicBlock * falseBlock)
{
	auto curFunc = llvmFunc;
	llvm::IRBuilder<> &builder = *context->getIRBuilder();
	size_t condCount = this->conditions.size();
	size_t codeCount = this->codes.size();
	if (condCount > 0) {
		llvm::BasicBlock *branch = llvm::BasicBlock::Create(*context->getLLVMContext(), "branch_cond", curFunc);
		llvm::BasicBlock *matched = llvm::BasicBlock::Create(*context->getLLVMContext(), "matched", curFunc);
		builder.CreateBr(branch);
		builder.SetInsertPoint(branch);
		for (size_t i = 0; i < this->conditions.size(); ++i)
		{
			llvm::Value *res = this->conditions[i]->generateIR(context).getValue();
			builder.CreateCondBr(res, matched, falseBlock);
		}
		builder.SetInsertPoint(matched);
		for (size_t i = 0; i < this->codes.size(); ++i)
		{
			llvm::Value *res = this->codes[i]->generateIR(context).getValue();
			if (i == this->codes.size() - 1)
			{
				builder.CreateRet(res);
			}
		}
		return branch;
	}
	else { //condCount == 0
		llvm::BasicBlock *matched = llvm::BasicBlock::Create(*context->getLLVMContext(), "branch", curFunc);
		builder.CreateBr(matched);
		builder.SetInsertPoint(matched);
		for (size_t i = 0; i < this->codes.size(); ++i)
		{
			llvm::Value *res = this->codes[i]->generateIR(context).getValue();
			if (i == this->codes.size() - 1)
			{
				builder.CreateRet(res);
			}
		}
		return matched;
	}
}
