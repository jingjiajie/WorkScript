#pragma once
#include "InstantializeContext.h"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/Object/ObjectFile.h>
#include <llvm/Support/TargetSelect.h>

namespace WorkScript {
	class GenerateContext
	{
	public:
		inline GenerateContext(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule, llvm::IRBuilder<> *irBuilder, InstantializeContext *instCtx)
		{
			this->setIRBuilder(irBuilder);
			this->setLLVMContext(llvmContext);
			this->setLLVMModule(llvmModule);
			this->setInstantializeContext(instCtx);
		}

		inline llvm::LLVMContext * getLLVMContext() const { return this->llvmContext; }
		inline void setLLVMContext(llvm::LLVMContext *llvmContext) { this->llvmContext = llvmContext; }
		inline llvm::Module * getLLVMModule() const { return this->llvmModule; }
		inline void setLLVMModule(llvm::Module *llvmModule) { this->llvmModule = llvmModule; }
		inline llvm::IRBuilder<> * getIRBuilder() const { return this->irBuilder; }
		inline void setIRBuilder(llvm::IRBuilder<> *irBuilder) { this->irBuilder = irBuilder; }
		inline InstantializeContext * getInstantializeContext() { return this->instantializeContext; }
		inline void setInstantializeContext(InstantializeContext *ctx) { this->instantializeContext = ctx; }
		inline bool isLeftValue() const { return this->_isLeftValue; }
		inline void setLeftValue(bool isLVal) { this->_isLeftValue = isLVal; }
	private:
		llvm::LLVMContext * llvmContext = nullptr;
		llvm::Module * llvmModule = nullptr;
		llvm::IRBuilder<> * irBuilder = nullptr;
		InstantializeContext *instantializeContext = nullptr;
		bool _isLeftValue = false;
	};
}