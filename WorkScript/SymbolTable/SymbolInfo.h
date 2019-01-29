#pragma once
#include <unordered_map>
#include "GenerateContext.h"
#include "DebugInfo.h"

namespace WorkScript 
{
	class Constant;
	class Type;

	class SymbolInfo
	{
	public:
		inline SymbolInfo(const DebugInfo &d,  const std::wstring &name, Type *type = nullptr)
		:name(name),type(type),debugInfo(d){}
		inline SymbolInfo() {}

		~SymbolInfo();

		inline void setLLVMValue(llvm::Value *llvmVal) { this->llvmValue = llvmVal; }
		inline void setLLVMValuePtr(llvm::Value *llvmValPtr) { this->llvmValuePtr = llvmValPtr; }
		llvm::Value * getLLVMValue(GenerateContext *context);
		llvm::Value * getLLVMValuePtr(GenerateContext *context);
		const DebugInfo &getDebugInfo() const;
		void setDebugInfo(const DebugInfo &debugInfo);

		inline Type * getType() const { return this->type; }
		inline std::wstring getName() const { return this->name; }
		void promoteType(Type *type);

	private:
		std::wstring name;
		Constant *value = nullptr;
		Type * type = nullptr;
		llvm::Value *llvmValue = nullptr;
		llvm::Value *llvmValuePtr = nullptr;
		DebugInfo debugInfo;
	};
}