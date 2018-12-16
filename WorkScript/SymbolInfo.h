#pragma once
#include "stdafx.h"
#include "GenerateContext.h"

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

		llvm::Value * getLLVMValue(GenerateContext *context);

		inline Type * getType() const { return this->type; }
		inline std::wstring getName() const { return this->name; }

	private:
		std::wstring name;
		Type * type = nullptr;
		llvm::Value *llvmValue;
	};
}