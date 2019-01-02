#pragma once
#include <vector>
#include "Expression.h"

namespace WorkScript 
{
	class BranchFunction;
	class Parameter;

	class FunctionBranch 
	{
	public:
		inline FunctionBranch(BranchFunction *function, size_t branchID, Location loc)
			:abstractSymbolTable(branchID)
		{
			this->function = function;
			this->location = loc;
			this->branchID = branchID;
		}

		inline FunctionBranch(BranchFunction *function, size_t branchID, Location loc, const std::vector<Expression*> &constraints, const std::vector<Expression*> &implements)
			:abstractSymbolTable(branchID)
		{
			this->function = function;
			this->location = loc;
			this->constraints = constraints;
			this->implements = implements;
			this->branchID = branchID;
		}

		~FunctionBranch();

		Type *getReturnType(InstantializeContext *instCtx);
		void setConstraints(const std::vector<Expression*> constraints);
		void setImplements(const std::vector<Expression*> implements);
		llvm::BasicBlock * generateBlock(GenerateContext *context, llvm::Function *llvmFunc, llvm::BasicBlock *falseBlock);
		inline Location getLocation() const { return this->location; };
		inline SymbolTable * getAbstractSymbolTable() { return &this->abstractSymbolTable; }
		inline Parameter * getParameter(size_t index) { return this->parameters[index]; }
		inline std::vector<Parameter*> getParameters() { return this->parameters; }
		inline void setParameters(const std::vector<Parameter*> &params) { this->parameters = params; }
		inline size_t getBranchID() const { return this->branchID; }
	private:
		BranchFunction * function;
		size_t branchID = 0;
		std::vector<Parameter*> parameters;
		std::vector<Expression*> constraints;
		std::vector<Expression*> implements;
		Location location;
		BlockSymbolTable abstractSymbolTable;
	};
}