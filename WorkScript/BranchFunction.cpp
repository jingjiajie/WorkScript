#include "stdafx.h"
#include "BranchFunction.h"
#include "FunctionBranch.h"

using namespace WorkScript;
using namespace std;

BranchFunction::~BranchFunction()
{
	for (auto br : this->branches)
	{
		delete br;
	}
}

Type * WorkScript::BranchFunction::getReturnType(InstantializeContext * instCtx)
{
	/*	推导返回值：
	*	如果声明了返回值类型，则以声明为准
	*	否则，遍历所有函数分支，忽略所有nullptr（未知）的返回值
	*	取所有可推导返回值中类型最高的作为函数返回值，	其他分支在返回时视情况做相应的类型转换
	*	如果所有分支返回值都为nullptr（未知），则函数返回值为nullptr
	*/
	if (this->abstractType->getReturnType()) {
		return this->abstractType->getReturnType();
	}
	SymbolTable instSymbolTable;
	auto paramTypes = this->getParameterTypes(instCtx);
	for (size_t i = 0; i < this->getParameterCount(); ++i) {
		SymbolInfo *curInfo = instSymbolTable.setSymbol(L"@" + to_wstring(i), paramTypes[i]);
	}
	auto prevTable = instCtx->getInstanceSymbolTable();
	instCtx->setInstanceSymbolTable(&instSymbolTable);
	Type *returnType = nullptr;
	if (!instCtx->getFunctionTypeCache(this, paramTypes, &returnType)) {
		instCtx->setFunctionTypeCache(this, paramTypes, nullptr);
		//推导每个分支的返回值，取最高类型
		for (size_t i = 0; i < this->branches.size(); ++i) {

			Type *curReturnType = this->branches[i]->getReturnType(instCtx);
			if (!curReturnType) continue;
			returnType = Type::getPromotedType(curReturnType, returnType);
		}
	}
	instCtx->setInstanceSymbolTable(prevTable);
	instCtx->setFunctionTypeCache(this, paramTypes, returnType);
	return returnType;
}

GenerateResult WorkScript::BranchFunction::generateLLVMIR(GenerateContext * context)
{
	llvm::Function *llvmFunc = this->getLLVMFunction(context, true);
	//如果没有实现，则只生成函数声明，且不进行命名粉碎
	if (this->branches.size() > 0) {
		llvmFunc = this->getLLVMFunction(context, true);
		InstantializeContext *instCtx = context->getInstantializeContext();
		auto prevTable = instCtx->getInstanceSymbolTable();
		llvm::IRBuilder<> *prevBuilder = context->getIRBuilder();
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
		llvm::BasicBlock *prevBlock = notMatched;
		//遍历分支，为每个分支生成代码
		for (size_t i = 0; i < this->branches.size(); ++i)
		{
			FunctionBranch *curBranch = this->branches[branchCount - 1 - i];
			prevBlock = curBranch->generateBlock(context, llvmFunc, prevBlock);
		}
		builder.SetInsertPoint(entry);
		builder.CreateBr(prevBlock);
		//如果全部匹配失败，则返回未定义值
		builder.SetInsertPoint(notMatched);
		builder.CreateRet(llvm::UndefValue::get(this->getReturnType(instCtx)->getLLVMType(context)));
		context->setIRBuilder(prevBuilder);
		instCtx->setInstanceSymbolTable(prevTable);
	}
	llvm::verifyFunction(*llvmFunc);
	return (llvm::Value*)llvmFunc;
}

size_t WorkScript::BranchFunction::addBranch(FunctionBranch *branch)
{
	auto params = branch->getParameters();
	if (params.size() != this->getParameterCount()) {
		//Location信息
		throw WorkScriptException(Location(), L"函数参数不匹配！");
	}
	this->branches.push_back(branch);
	return this->branches.size() - 1;
}

