#pragma once
#include "InstantialContext.h"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/Object/ObjectFile.h>
#include <llvm/Support/TargetSelect.h>

namespace WorkScript {
	class AbstractContext;
	class FunctionCache;

	class GenerateContext
	{
	public:
		inline GenerateContext(llvm::LLVMContext *llvmContext, llvm::Module *llvmModule, llvm::IRBuilder<> *irBuilder,
				AbstractContext *abstractContext, FunctionCache *cache,const std::wstring &blockPrefix = L"", BlockAttribute blockAttributes = 0x00)noexcept
			:llvmContext(llvmContext), llvmModule(llvmModule),irBuilder(irBuilder), instantialContext(abstractContext,cache,blockPrefix,blockAttributes) { }

		inline GenerateContext(const GenerateContext &base, const std::wstring &blockPrefix = L"")noexcept
			:llvmContext(base.llvmContext), llvmModule(base.llvmModule),irBuilder(base.irBuilder), instantialContext(base.instantialContext){ }

		inline llvm::LLVMContext * getLLVMContext() const noexcept { return this->llvmContext; }
		inline void setLLVMContext(llvm::LLVMContext *llvmContext) noexcept { this->llvmContext = llvmContext; }
		inline llvm::Module * getLLVMModule() const noexcept { return this->llvmModule; }
		inline void setLLVMModule(llvm::Module *llvmModule) noexcept { this->llvmModule = llvmModule; }
		inline llvm::IRBuilder<> * getIRBuilder() const noexcept { return this->irBuilder; }
		inline void setIRBuilder(llvm::IRBuilder<> *irBuilder) noexcept { this->irBuilder = irBuilder; }
		inline InstantialContext * getInstantialContext() noexcept { &return this->instantialContext; }
		inline bool isLeftValue() const noexcept { return this->_isLeftValue; }
		inline void setLeftValue(bool isLVal) noexcept { this->_isLeftValue = isLVal; }
	private:
		llvm::LLVMContext * llvmContext = nullptr;
		llvm::Module * llvmModule = nullptr;
		llvm::IRBuilder<> * irBuilder = nullptr;
		InstantialContext instantialContext;
		bool _isLeftValue = false;
	};
}
