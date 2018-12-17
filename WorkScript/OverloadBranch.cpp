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

void WorkScript::OverloadBranch::bindSymbols()
{
	for (Expression *expr : this->conditions) {
		expr->bindSymbols();
	}
	for (Expression *expr : this->codes) {
		expr->bindSymbols();
	}
}

llvm::BasicBlock * WorkScript::OverloadBranch::generateBlock(GenerateContext * context, llvm::Function *llvmFunc, llvm::BasicBlock * falseBlock)
{
	auto curFunc = llvmFunc;
	llvm::BasicBlock *cond = llvm::BasicBlock::Create(*context->getLLVMContext(), "cond", curFunc);
	llvm::BasicBlock *matched = llvm::BasicBlock::Create(*context->getLLVMContext(), "matched", curFunc);
	llvm::IRBuilder<> &builder = *context->getIRBuilder();
	builder.CreateBr(cond);
	builder.SetInsertPoint(cond);
	for (size_t i = 0; i < this->conditions.size(); ++i)
	{
		llvm::Value *res = this->conditions[i]->generateIR(context).getValue();
		builder.CreateCondBr(res, matched, falseBlock);
	}
	builder.SetInsertPoint(matched);
	for (size_t i = 0; i < this->codes.size(); ++i)
	{
		llvm::Value *res = this->codes[i]->generateIR(context).getValue();
		if(i == this->codes.size() - 1)
		{
			builder.CreateRet(res);
		}
	}
	return cond;
}
