#pragma once
#include "stdafx.h"

//class llvm::LLVMContext;
//class llvm::Module;
//class llvm::ConstantFolder;
//class llvm::IRBuilderDefaultInserter;
//template <typename T = ConstantFolder, typename Inserter = IRBuilderDefaultInserter>
//class llvm::IRBuilder;

class GenerateContext
{
public:
	inline GenerateContext(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule, llvm::IRBuilder<> *irBuilder)
	{
		this->setIRBuilder(irBuilder);
		this->setLLVMContext(llvmContext);
		this->setLLVMModule(llvmModule);
	}

	inline ~GenerateContext(){}

	inline llvm::LLVMContext * getLLVMContext() const {
		return this->llvmContext;
	}

	inline void setLLVMContext(llvm::LLVMContext *llvmContext) {
		this->llvmContext = llvmContext;
	}

	inline llvm::Module * getLLVMModule() const {
		return this->llvmModule;
	}

	inline void setLLVMModule(llvm::Module *llvmModule) {
		this->llvmModule = llvmModule;
	}

	inline llvm::IRBuilder<> * getIRBuilder() const {
		return this->irBuilder;
	}

	inline void setIRBuilder(llvm::IRBuilder<> *irBuilder) {
		this->irBuilder = irBuilder;
	}

	inline llvm::Function * getCurrentFunction()
	{
		return this->currentFunction;
	}

	inline void setCurrentFunction(llvm::Function *curFunc)
	{
		this->currentFunction = curFunc;
	}

	inline llvm::Value * getLocalVariable(const std::wstring &name)
	{
		auto it = this->variables.find(name);
		if (it == this->variables.end())return nullptr;
		else return it->second;
	}

	inline llvm::Value * setLocalVariable(const std::wstring &name, llvm::Type *type)
	{
		llvm::Value *var = this->irBuilder->CreateAlloca(type, nullptr, boost::locale::conv::from_utf(name, "UTF-8"));
		this->variables[name] = var;
		return var;
	}
private:
	llvm::LLVMContext * llvmContext = nullptr;
	llvm::Module * llvmModule = nullptr;
	llvm::IRBuilder<> * irBuilder = nullptr;
	llvm::Function *currentFunction = nullptr;
	std::unordered_map<std::wstring, llvm::Value*> variables;
};