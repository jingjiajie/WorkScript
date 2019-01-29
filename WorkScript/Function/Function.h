#pragma once
#include <vector>

#include "Parameter.h"
#include "GenerateContext.h"
#include "GenerateResult.h"
#include "SymbolTable.h"

namespace WorkScript {
	class FunctionType;
	class FunctionBranch;

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
		Function(AbstractContext *baseContext,
			const std::wstring &name, 
			const std::vector<Type*> &paramTypes, 
			Type *returnType, 
			bool declaredReturnType = false,
			bool isRuntimeVarargs = false, 
			bool isStaticVarargs = false);

		virtual ~Function();
		std::wstring getMangledFunctionName(const DebugInfo &d, InstantializeContext *ctx) const;
		static std::wstring getStdParameterName(size_t paramIndex);
		virtual GenerateResult generateLLVMIR(const DebugInfo &d, GenerateContext *context);
		llvm::Function * getLLVMFunction(const DebugInfo &d, GenerateContext *context, bool declareOnly = false);

		inline FunctionType *getAbstractType() { return this->abstractType; }
		virtual Type *getReturnType(const DebugInfo &d, InstantializeContext *instCtx);
		virtual void setReturnType(Type *type);
		static MatchResult matchByParameters(const DebugInfo &d, const std::vector<Type*> &declParamTypes, const std::vector<Type*> &realParamTypes, bool isRuntimeVarargs, bool isStaticVarargs);
		MatchResult matchByParameters(const DebugInfo &d, const std::vector<Type*> &paramTypes);

		Program * getProgram() const { return this->program; }
		inline size_t getParameterCount() const { return this->abstractType->getParameterCount(); }
		std::vector<Type*> getParameterTypes(const DebugInfo &d, InstantializeContext *context) const;
		inline std::wstring getName() const { return this->name; }
		inline bool isDeclaredReturnType()const { return this->declaredReturnType; }
		inline bool isRuntimeVarargs() const { return this->runtimeVarargs; }
		inline bool isStaticVarargs() const { return this->staticVarargs; }
		inline AbstractContext * getBaseContext() { return this->baseContext; }
		size_t addBranch(FunctionBranch *branch);

		size_t getBranchCount() const
		{ return this->branches.size(); }
	protected:
		std::wstring name;
		Program *program = nullptr;
		std::vector<ParamTypesAndLLVMFunction> llvmFunctions;
		FunctionType *abstractType;
		bool declaredReturnType = false;
		bool runtimeVarargs = false;
		bool staticVarargs = false;
		AbstractContext *baseContext;
		std::vector<FunctionBranch *> branches;
	};
}