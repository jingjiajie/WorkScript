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
			this->setType(type);
			this->setName(name);
		}

		llvm::Value * getLLVMValue(GenerateContext *context) const;

		inline const Type * getType() const
		{
			return this->type;
		}

		inline void setType(Type *type)
		{
			this->type = type;
		}

		inline const std::wstring &getName() const
		{
			return this->name;
		}

		inline void setName(const std::wstring &name)
		{
			this->name = name;
		}

	private:
		std::wstring name;
		Type * type = nullptr;
		llvm::Value *llvmValue;
	};
}