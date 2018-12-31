#pragma once
#include "stdafx.h"
#include "GenerateContext.h"
#include "Constant.h"

namespace WorkScript 
{
	class Type;
	class SymbolInfo 
	{
	public:
		inline SymbolInfo() {}

		inline SymbolInfo(const std::wstring &name, Type *type = nullptr)
		{
			this->type = type;
			this->name = name;
		}

		inline SymbolInfo(const std::wstring &name, Type *type, Constant *value)
		{
			this->type = type;
			this->name = name;
			this->value = value;
		}

		~SymbolInfo();

		inline void setLLVMValue(llvm::Value *llvmVal) { this->llvmValue = llvmVal; }
		inline void setLLVMValuePtr(llvm::Value *llvmValPtr) { this->llvmValuePtr = llvmValPtr; }
		llvm::Value * getLLVMValue(GenerateContext *context);
		llvm::Value * getLLVMValuePtr(GenerateContext *context);

		inline Type * getType() const { return this->type; }
		inline std::wstring getName() const { return this->name; }
		void promoteType(Type *type);
	private:
		std::wstring name;

		Constant *value = nullptr;
		Type * type = nullptr;
		llvm::Value *llvmValue = nullptr;
		llvm::Value *llvmValuePtr = nullptr;
	};
}