#include "stdafx.h"
#include "FunctionBranch.h"
#include "InstantializeContext.h"
#include "Parameter.h"
#include "BranchFunction.h"
#include "Locale.h"

using namespace WorkScript;
using namespace std;

WorkScript::FunctionBranch::~FunctionBranch()
{
	for (auto expr : this->constraints) {
		delete expr;
	}
	for (auto expr : this->implements) {
		delete expr;
	}
}

Type * WorkScript::FunctionBranch::getReturnType(InstantializeContext * ctx)
{
	size_t implCount = this->implements.size();
	if (implCount == 0)return Program::getVoidType();
	SymbolTable instSymbolTable;
	for (size_t i = 0; i < this->parameters.size(); ++i) {
		//获取@n的符号信息
		SymbolInfo *stdParamInfo = ctx->getSymbolInfo(L"@" + to_wstring(i));
		//获取当前分支参数的符号信息，加入符号表
		Parameter *myParam = this->parameters[i];
		SymbolInfo *myParamInfo = instSymbolTable.setSymbol(myParam->getName(), stdParamInfo->getType());
	}
	InstantializeContext newCtx(&this->abstractSymbolTable, &instSymbolTable);
	return this->implements[implCount - 1]->getType(&newCtx);
}

void WorkScript::FunctionBranch::setConstraints(const std::vector<Expression*> constraints)
{
	if (this->constraints.size() > 0) {
		for (auto expr : this->constraints) {
			delete expr;
		}
	}
	this->constraints = constraints;
}

void WorkScript::FunctionBranch::setImplements(const std::vector<Expression*> implements)
{
	if (this->implements.size() > 0) {
		for (auto expr : this->implements) {
			delete expr;
		}
	}
	this->implements = implements;
}

llvm::BasicBlock * WorkScript::FunctionBranch::generateBlock(GenerateContext * context, llvm::Function *llvmFunc, llvm::BasicBlock * falseBlock)
{
	//遍历参数，将参数@0,@1...赋值到本分支函数的参数符号
	auto prevInstCtx = context->getInstantializeContext();
	llvm::IRBuilder<> &builder = *context->getIRBuilder();
	SymbolTable instSymbolTable;
	for (size_t i = 0; i < this->parameters.size();++i) {
		//获取@n的符号信息
		SymbolInfo *stdParamInfo = prevInstCtx->getSymbolInfo(L"@" + to_wstring(i));
		llvm::Value *stdLLVMParam = stdParamInfo->getLLVMValue(context);
		//获取当前分支参数的符号信息，加入符号表
		Parameter *myParam = this->parameters[i];
		SymbolInfo *myParamInfo = instSymbolTable.setSymbol(myParam->getName(), stdParamInfo->getType());
		//生成llvm赋值，将标准参数赋值到当前分支参数
		llvm::Value *myLLVMParamPtr = myParamInfo->getLLVMValuePtr(context);
		builder.CreateStore(stdLLVMParam, myLLVMParamPtr);
	}
	InstantializeContext newInstCtx(&this->abstractSymbolTable, &instSymbolTable);
	context->setInstantializeContext(&newInstCtx);

	llvm::Function *curFunc = llvmFunc;
	size_t condCount = this->constraints.size();
	size_t codeCount = this->implements.size();
	llvm::BasicBlock *ret = nullptr;
	if (condCount > 0) {
		llvm::BasicBlock *branch = llvm::BasicBlock::Create(*context->getLLVMContext(), "branch_cond", curFunc);
		llvm::BasicBlock *matched = llvm::BasicBlock::Create(*context->getLLVMContext(), "matched", curFunc);
		builder.CreateBr(branch);
		builder.SetInsertPoint(branch);
		for (size_t i = 0; i < this->constraints.size(); ++i)
		{
			llvm::Value *res = this->constraints[i]->generateIR(context).getValue();
			builder.CreateCondBr(res, matched, falseBlock);
		}
		builder.SetInsertPoint(matched);
		for (size_t i = 0; i < this->implements.size(); ++i)
		{
			llvm::Value *res = this->implements[i]->generateIR(context).getValue();
			if (i == this->implements.size() - 1)
			{
				builder.CreateRet(res);
			}
		}
		ret = branch;
	}
	else { //condCount == 0
		llvm::BasicBlock *matched = llvm::BasicBlock::Create(*context->getLLVMContext(), "branch", curFunc);
		builder.CreateBr(matched);
		builder.SetInsertPoint(matched);
		for (size_t i = 0; i < this->implements.size(); ++i)
		{
			llvm::Value *res = this->implements[i]->generateIR(context).getValue();
			if (i == this->implements.size() - 1)
			{
				builder.CreateRet(res);
			}
		}
		ret = matched;
	}
	context->setInstantializeContext(prevInstCtx);
	return ret;
}
