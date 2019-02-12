#pragma once
#include <unordered_map>
#include "DebugInfo.h"
#include "Type.h"

namespace WorkScript
{
    class Value;
	class GenerateContext;

	class SymbolInfo
	{
	public:
		inline SymbolInfo(const DebugInfo &d, const std::wstring &name, Type *type, LinkageType lt, Value *value = nullptr) noexcept
				: name(name), value(value), type(type), debugInfo(d), linkageType(lt)
		{ }

		inline SymbolInfo(const DebugInfo &d, const std::wstring &name, Type *type, LinkageType lt, llvm::Value *llvmValue) noexcept
				: name(name), type(type), linkageType(lt), llvmValue(llvmValue), debugInfo(d)
		{ }

		inline SymbolInfo() noexcept = default;

		~SymbolInfo() noexcept;

		inline void setLLVMValue(llvm::Value *llvmVal)
		{ this->llvmValue = llvmVal; }

		inline void setLLVMValuePtr(llvm::Value *llvmValPtr)
		{ this->llvmValuePtr = llvmValPtr; }

		llvm::Value *getLLVMValue(const DebugInfo &d, GenerateContext *context);

		llvm::Value *getLLVMValuePtr(const DebugInfo &d, GenerateContext *context);

		inline const Value *getValue() const noexcept
		{ return this->value; }

		inline Value *getValue() noexcept
		{ return this->value; }

		void setValue(Value *value) noexcept;

		const DebugInfo &getDebugInfo() const noexcept;

		void setDebugInfo(const DebugInfo &debugInfo) noexcept;

		inline Type *getType() const
		{ return this->type; }

		inline std::wstring getName() const
		{ return this->name; }

		inline LinkageType getLinkageType() const
		{ return this->linkageType; }

		inline void setLinkageType(LinkageType lt)
		{ this->linkageType = lt; }

		void promoteType(Type *type);

	private:
		std::wstring name;
		Value *value = nullptr;
		Type *type = nullptr;
		LinkageType linkageType = LinkageType::INTERNAL;
		llvm::Value *llvmValue = nullptr;
		llvm::Value *llvmValuePtr = nullptr;
		DebugInfo debugInfo;
	};
}