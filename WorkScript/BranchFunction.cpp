#include "stdafx.h"
#include "BranchFunction.h"
#include "FunctionBranch.h"

using namespace WorkScript;
using namespace std;

WorkScript::BranchFunction::~BranchFunction()
{
	for (FunctionBranch *br : this->branches)delete br;
}

Type * WorkScript::BranchFunction::getReturnType(FunctionInstantializeContext * instCtx)
{
	//TODO 如何推导返回值？
	SymbolTable instSymbolTable;
	auto paramTypes = this->getParameterTypes(instCtx);
	for (size_t i = 0; i < this->getParameterCount(); ++i) {
		SymbolInfo *curInfo = instSymbolTable.setSymbol(L"@" + to_wstring(i), paramTypes[i]);
	}
	auto prevTable = instCtx->getInstanceSymbolTable();
	instCtx->setInstanceSymbolTable(&instSymbolTable);
	auto ret = this->branches[0]->getReturnType(instCtx);
	instCtx->setInstanceSymbolTable(prevTable);
	return ret;
}

GenerateResult WorkScript::BranchFunction::generateLLVMIR(GenerateContext * context)
{
	FunctionInstantializeContext *instCtx = (FunctionInstantializeContext*)context->getInstantializeContext();
	auto prevTable = instCtx->getInstanceSymbolTable();
	llvm::IRBuilder<> *prevBuilder = context->getIRBuilder();
	llvm::Function *llvmFunc = this->getLLVMFunction(context, true);
	llvm::BasicBlock *entry = llvm::BasicBlock::Create(*context->getLLVMContext(), "entry", llvmFunc);
	llvm::BasicBlock *notMatched = llvm::BasicBlock::Create(*context->getLLVMContext(), "not_matched", llvmFunc);
	llvm::IRBuilder<> builder(entry);
	context->setIRBuilder(&builder);
	//生成参数的LLVM Value
	SymbolTable instSymbolTable;
	auto paramTypes = this->getParameterTypes(instCtx);
	llvm::Argument *itArg = llvmFunc->arg_begin();
	for (size_t i = 0; i < this->getParameterCount(); ++i) {
		SymbolInfo *curInfo = instSymbolTable.setSymbol(L"@" + to_wstring(i), paramTypes[i]);
		curInfo->setLLVMValue(itArg);
		++itArg;
	}
	instCtx->setInstanceSymbolTable(&instSymbolTable);
	size_t branchCount = this->branches.size();
	llvm::BasicBlock *curFalseBlock = notMatched;
	//遍历分支，为每个分支生成代码
	for (size_t i = 0; i < this->branches.size(); ++i)
	{
		FunctionBranch *curBranch = this->branches[branchCount - 1 - i];
		builder.SetInsertPoint(entry);
		curFalseBlock = curBranch->generateBlock(context, llvmFunc, curFalseBlock);
	}
	//如果全部匹配失败，则返回未定义值
	builder.SetInsertPoint(notMatched);
	builder.CreateRet(llvm::UndefValue::get(this->getReturnType(instCtx)->getLLVMType(context)));
	string str;
	bool vret = llvm::verifyFunction(*llvmFunc, &llvm::raw_string_ostream(str));
	context->setIRBuilder(prevBuilder);
	instCtx->setInstanceSymbolTable(prevTable);
	return (llvm::Value*)llvmFunc;
}

void WorkScript::BranchFunction::addBranch(FunctionBranch * branch)
{
	auto params = branch->getParameters();
	if (params.size() != this->getParameterCount()) {
		throw WorkScriptException(L"函数参数不匹配！");
	}
	this->branches.push_back(branch);
}
