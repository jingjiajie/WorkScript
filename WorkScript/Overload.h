#pragma once
#include <vector>

#include "Parameter.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "SymbolTable.h"

namespace WorkScript {
	class Function;
	class Overload {
	public:
		inline Overload(Function *func, const std::vector<Parameter*> &params, Type *returnType)
		{
			this->function = func;
			this->returnType = returnType;
			this->parameters = params;
		}

		virtual ~Overload();
		std::wstring getMangledFunctionName() const;
		llvm::Function * getLLVMFunction(GenerateContext *context);

		bool matchByParameters(const std::vector<Type*> &paramTypes);

		inline size_t getParameterCount() const
		{
			return this->parameters.size();
		}

		inline Parameter * getParameter(size_t index)
		{
			return this->parameters[index];
		}

		inline void setParameters(const std::vector<Parameter*> &params)
		{
			this->parameters = params;
		}

		inline Function *getFunction()const
		{
			return this->function;
		}

		inline void setFunction(Function *f)
		{
			this->function = f;
		}

		Parameter * getThisParameter();

		inline Type *getReturnType()
		{
			return this->returnType;
		}

		inline void setReturnType(Type *returnType)
		{
			this->returnType;
		}

		inline SymbolTable * getSymbolTable()
		{
			return &this->symbolTable;
		}
	protected:
		std::vector<Parameter*> parameters;
		Type *returnType = nullptr;
		Function *function = nullptr;
		llvm::Function *llvmFunction = nullptr;
		SymbolTable symbolTable;
	};
}