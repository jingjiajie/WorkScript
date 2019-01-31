#pragma once
#include <unordered_map>
#include "GenerateContext.h"
#include "DebugInfo.h"
#include "Type.h"

namespace WorkScript 
{
	class Constant;

	class SymbolInfo
	{
	public:
		inline SymbolInfo(const DebugInfo &d,  const std::wstring &name, Type *type, LinkageType lt)
		:name(name),type(type),debugInfo(d), linkageType(lt){}
		inline SymbolInfo() {}

		~SymbolInfo();

		inline void setLLVMValue(llvm::Value *llvmVal) { this->llvmValue = llvmVal; }
		inline void setLLVMValuePtr(llvm::Value *llvmValPtr) { this->llvmValuePtr = llvmValPtr; }
		llvm::Value * getLLVMValue(const DebugInfo &d, GenerateContext *context);
		llvm::Value * getLLVMValuePtr(const DebugInfo &d, GenerateContext *context);
		const DebugInfo &getDebugInfo() const;
		void setDebugInfo(const DebugInfo &debugInfo);

		inline Type * getType() const { return this->type; }
		inline std::wstring getName() const { return this->name; }
		void promoteType(Type *type);

	private:
		std::wstring name;
		Constant *value = nullptr;
		Type * type = nullptr;
		LinkageType linkageType;
		llvm::Value *llvmValue = nullptr;
		llvm::Value *llvmValuePtr = nullptr;
		DebugInfo debugInfo;
	};
}