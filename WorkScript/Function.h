#pragma once
#include <vector>

#include "Parameter.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "SymbolTable.h"
#include "Constant.h"

namespace WorkScript {
	class FunctionType;

	class ParamTypesAndLLVMFunction {
	public:
		ParamTypesAndLLVMFunction(std::vector<Type*> types, llvm::Function* func)
			:parameterTypes(types), llvmFunction(func) {}

		bool match(std::vector<Type*> paramTypes);
		inline llvm::Function *getLLVMFunction() { return this->llvmFunction; }
	protected:
		std::vector<Type*> parameterTypes; 
		llvm::Function* llvmFunction;
	};

	class Function {
	public:
		Function(Program *program, const std::wstring &name, const std::vector<Type*> &paramTypes, Type *returnType);

		virtual ~Function();
		std::wstring getMangledFunctionName(InstantializeContext *ctx) const;
		static std::wstring getStdParameterName(size_t paramIndex);
		virtual GenerateResult generateLLVMIR(GenerateContext *context) = 0;
		llvm::Function * getLLVMFunction(GenerateContext *context, bool declareOnly = false);

		inline FunctionType *getType() { return this->abstractType; }
		virtual Type *getReturnType(InstantializeContext *instCtx) = 0;
		virtual void setReturnType(Type *type);
		bool matchByParameters(const std::vector<Type*> &paramTypes);

		inline size_t getParameterCount() const { return this->abstractType->getParameterCount(); }
		inline std::vector<Type*> getParameterTypes(InstantializeContext *context) const;
		inline std::wstring getName() const { return this->name; }
	protected:
		std::wstring name;
		Program *program = nullptr;
		std::vector<ParamTypesAndLLVMFunction> llvmFunctions;
		FunctionType *abstractType;
	};
}