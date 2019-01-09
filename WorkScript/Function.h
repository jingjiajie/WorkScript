#pragma once
#include <vector>

#include "Parameter.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "SymbolTable.h"
#include "Constant.h"

namespace WorkScript {
	class FunctionType;

	enum MatchResult {
		MISMATCHED, MATCHED, COMPROMISE_MATCHED,
	};

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
		Function(Program *program, 
			const std::wstring &name, 
			const std::vector<Type*> &paramTypes, 
			Type *returnType, 
			bool declaredReturnType = false,
			bool isRuntimeVarargs = false, 
			bool isStaticVarargs = false);

		virtual ~Function();
		std::wstring getMangledFunctionName(InstantializeContext *ctx) const;
		static std::wstring getStdParameterName(size_t paramIndex);
		virtual GenerateResult generateLLVMIR(GenerateContext *context) = 0;
		llvm::Function * getLLVMFunction(GenerateContext *context, bool declareOnly = false);

		inline FunctionType *getType() { return this->abstractType; }
		virtual Type *getReturnType(InstantializeContext *instCtx) = 0;
		virtual void setReturnType(Type *type);
		//CommonAbstractContext * getAbstractContext() { return &this->abstractContext; }
		static MatchResult matchByParameters(const std::vector<Type*> &declParamTypes, const std::vector<Type*> &realParamTypes);
		MatchResult matchByParameters(const std::vector<Type*> &paramTypes);

		Program * getProgram() const { return this->program; }
		inline size_t getParameterCount() const { return this->abstractType->getParameterCount(); }
		inline std::vector<Type*> getParameterTypes(InstantializeContext *context) const;
		inline std::wstring getName() const { return this->name; }
		inline bool isDeclaredReturnType()const { return this->declaredReturnType; }
		inline bool isRuntimeVarargs() const { return this->runtimeVarargs; }
		inline bool isStaticVarargs() const { return this->staticVarargs; }
	protected:
		std::wstring name;
		Program *program = nullptr;
		std::vector<ParamTypesAndLLVMFunction> llvmFunctions;
		FunctionType *abstractType;
		bool declaredReturnType = false;
		bool runtimeVarargs = false;
		bool staticVarargs = false;
		//CommonAbstractContext abstractContext;
	};
}