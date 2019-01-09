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
	/*	�Ƶ�����ֵ��
	*	��������˷���ֵ���ͣ���������Ϊ׼
	*	���򣬱������к�����֧����������nullptr��δ֪���ķ���ֵ
	*	ȡ���п��Ƶ�����ֵ��������ߵ���Ϊ��������ֵ��	������֧�ڷ���ʱ���������Ӧ������ת��
	*	������з�֧����ֵ��Ϊnullptr��δ֪������������ֵΪnullptr
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
		//�Ƶ�ÿ����֧�ķ���ֵ��ȡ�������
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
	//���û��ʵ�֣���ֻ���ɺ����������Ҳ�������������
	if (this->branches.size() > 0) {
		llvmFunc = this->getLLVMFunction(context, true);
		InstantializeContext *instCtx = context->getInstantializeContext();
		auto prevTable = instCtx->getInstanceSymbolTable();
		llvm::IRBuilder<> *prevBuilder = context->getIRBuilder();
		llvm::BasicBlock *entry = llvm::BasicBlock::Create(*context->getLLVMContext(), "entry", llvmFunc);
		llvm::BasicBlock *notMatched = llvm::BasicBlock::Create(*context->getLLVMContext(), "not_matched", llvmFunc);
		llvm::IRBuilder<> builder(entry);
		context->setIRBuilder(&builder);
		//���ɲ�����LLVM Value
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
		//������֧��Ϊÿ����֧���ɴ���
		for (size_t i = 0; i < this->branches.size(); ++i)
		{
			FunctionBranch *curBranch = this->branches[branchCount - 1 - i];
			prevBlock = curBranch->generateBlock(context, llvmFunc, prevBlock);
		}
		builder.SetInsertPoint(entry);
		builder.CreateBr(prevBlock);
		//���ȫ��ƥ��ʧ�ܣ��򷵻�δ����ֵ
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
		//Location��Ϣ
		throw WorkScriptException(Location(), L"����������ƥ�䣡");
	}
	this->branches.push_back(branch);
	return this->branches.size() - 1;
}
