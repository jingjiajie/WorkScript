#pragma once
#include <vector>
#include "Expression.h"
#include "AbstractContext.h"

namespace WorkScript {
	class Parameter;

	class FunctionBranch 
	{
	public:
		FunctionBranch(Function *function, size_t branchID, DebugInfo loc);
		FunctionBranch(Function *function, size_t branchID, DebugInfo loc, const std::vector<Expression*> &constraints, const std::vector<Expression*> &implements);

		~FunctionBranch();

		Type *getReturnType(InstantializeContext *instCtx);
		void setConstraints(const std::vector<Expression*> &constraints);
		void setImplements(const std::vector<Expression*> &implements);
		llvm::BasicBlock * generateBlock(GenerateContext *context, llvm::Function *llvmFunc, llvm::BasicBlock *falseBlock);
		inline DebugInfo getLocation() const { return this->location; };
		inline Parameter * getParameter(size_t index) { return this->parameters[index]; }
		inline std::vector<Parameter*> getParameters() { return this->parameters; }
		inline void setParameters(const std::vector<Parameter*> &params) { this->parameters = params; }
		inline size_t getBlockID() const { return this->context.getBlockID(); }
		inline AbstractContext * getContext() { return &this->context; }
	private:
		Function * function;
		std::vector<Parameter*> parameters;
		std::vector<Expression*> constraints;
		std::vector<Expression*> implements;
		DebugInfo location;
		AbstractContext context;
	};
}