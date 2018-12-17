#pragma once
#include "stdafx.h"

namespace WorkScript {

	class SymbolTable;

	class GenerateContext
	{
	public:
		inline GenerateContext(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule, llvm::IRBuilder<> *irBuilder, SymbolTable *symbolTable = nullptr)
		{
			this->setIRBuilder(irBuilder);
			this->setLLVMContext(llvmContext);
			this->setLLVMModule(llvmModule);
			this->setCurrentSymbolTable(symbolTable);
		}

		inline llvm::LLVMContext * getLLVMContext() const { return this->llvmContext; }
		inline void setLLVMContext(llvm::LLVMContext *llvmContext) { this->llvmContext = llvmContext; }
		inline llvm::Module * getLLVMModule() const { return this->llvmModule; }
		inline void setLLVMModule(llvm::Module *llvmModule) { this->llvmModule = llvmModule; }
		inline llvm::IRBuilder<> * getIRBuilder() const { return this->irBuilder; }
		inline void setIRBuilder(llvm::IRBuilder<> *irBuilder) { this->irBuilder = irBuilder; }
		inline SymbolTable * getCurrentSymbolTable() const { return this->currentSymbolTable; }
		inline void setCurrentSymbolTable(SymbolTable *t) { this->currentSymbolTable = t; }
	private:
		llvm::LLVMContext * llvmContext = nullptr;
		llvm::Module * llvmModule = nullptr;
		llvm::IRBuilder<> * irBuilder = nullptr;
		SymbolTable *currentSymbolTable;
	};
}