#pragma once
#include "stdafx.h"
#include "InstantializeContext.h"

namespace WorkScript {
	class GenerateContext
	{
	public:
		inline GenerateContext(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule, llvm::IRBuilder<> *irBuilder)
		{
			this->setIRBuilder(irBuilder);
			this->setLLVMContext(llvmContext);
			this->setLLVMModule(llvmModule);
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