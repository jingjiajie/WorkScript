#pragma once
#include "stdafx.h"
#include "Expression.h"

namespace WorkScript {
	class Function;
	class Program;
	class Type
	{
	public:
		inline Type(Program *program, const std::wstring &name, Type *baseType = nullptr)
		{
			this->setBaseType(baseType);
			this->setName(name);
			this->program = program;
		}

		inline Type(Program *program, const std::wstring &name,llvm::Type *llvmType , Type *baseType = nullptr)
		{
			this->setBaseType(baseType);
			this->setName(name);
			this->llvmType = llvmType;
			this->program = program;
		}

		inline ~Type()
		{
		}

		Type * inferReturnType(const std::wstring &funcName, const std::vector<Type*> &params);

		inline bool equals(const Type *type) const
		{
			return type == this;
		}

		//类名
		inline const std::wstring & getName() const
		{
			return this->name;
		}

		inline void setName(const std::wstring &name)
		{
			this->name = name;
		}

		//基类
		bool isSubTypeOf(const Type *) const;

		const Type * getBaseType() const
		{
			return this->baseType;
		}

		inline void setBaseType(Type *base) 
		{
			this->baseType = base;
		}

		//成员函数
		void addMemberFunction(Function *func);

		Function * getMemberFunction(const std::wstring &name)
		{
			auto it = this->memberFunctions.find(name);
			if (it == this->memberFunctions.end())return nullptr;
			else return it->second;
		}

		llvm::Type * getLLVMType(GenerateContext *context)
		{
			return this->fGetLLVMType(this, context);
		}
	private:
		std::wstring name;
		Type * baseType;
		//成员函数引用Program中的函数。由Program负责释放
		std::unordered_map<std::wstring, Function*> memberFunctions;
		Program *program;
		llvm::Type *(*fGetLLVMType)(Type*,GenerateContext*);
	};
}