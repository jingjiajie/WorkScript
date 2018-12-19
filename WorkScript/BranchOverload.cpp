#include "stdafx.h"
#include "BranchOverload.h"
#include "OverloadBranch.h"

WorkScript::BranchOverload::~BranchOverload()
{
	for (OverloadBranch *br : this->branches)delete br;
}

GenerateResult WorkScript::BranchOverload::generateLLVMIR(GenerateContext * context)
{
	llvm::Function *func = this->getLLVMFunction(context);
	llvm::BasicBlock *entry = llvm::BasicBlock::Create(*context->getLLVMContext(), "entry", func);
	llvm::BasicBlock *notMatched = llvm::BasicBlock::Create(*context->getLLVMContext(), "not_matched", func);
	llvm::IRBuilder<> builder(entry);
	context->setIRBuilder(&builder);
	size_t branchCount = this->branches.size();
	llvm::BasicBlock *curFalseBlock = notMatched;
	for (size_t i = 0; i < this->branches.size(); ++i)
	{
		builder.SetInsertPoint(entry);
		curFalseBlock = this->branches[branchCount - 1 - i]->generateBlock(context, func, curFalseBlock);
	}
	//如果全部匹配失败，则返回未定义值
	builder.SetInsertPoint(notMatched);
	builder.CreateRet(llvm::UndefValue::get(this->returnType->getLLVMType(context)));
	llvm::verifyFunction(*func);
	return (llvm::Value*)func;
}
