#include "stdafx.h"
#include "OverloadBranch.h"

llvm::BasicBlock * WorkScript::OverloadBranch::generateBlock(GenerateContext * context, llvm::BasicBlock * falseBlock, llvm::BasicBlock * mergeBlock)
{
	auto builder = context->getIRBuilder();
	auto curFunc = context->getCurrentFunction();
	llvm::BasicBlock *block = llvm::BasicBlock::Create(*context->getLLVMContext(), "if", curFunc);
	llvm::BasicBlock *trueBlock = llvm::BasicBlock::Create(*context->getLLVMContext(), "if_true", curFunc);
	builder->SetInsertPoint(block);
	for (size_t i = 0; i < this->conditions.size(); ++i)
	{
		llvm::Value *res = this->conditions[i]->generateIR(context).getValue();
		builder->CreateCondBr(res, trueBlock, falseBlock);
	}
	builder->SetInsertPoint(trueBlock);
	for (size_t i = 0; i < this->codes.size(); ++i)
	{
		llvm::Value *res = this->codes[i]->generateIR(context).getValue();
		if(i == this->codes.size())
		{ 
			builder->CreateRet(res);
		}
	}
	builder->CreateBr(mergeBlock);
	return block;
}
