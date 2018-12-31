#pragma once
#include "stdafx.h"
#include "ParameterTemplate.h"
#include "SymbolTable.h"

namespace WorkScript {
	class FunctionTemplate;
	class Function;
	class Function;
	class OverloadTemplate {
	public:
		inline OverloadTemplate(FunctionTemplate *func,const std::vector<ParameterTemplate*> &params, Type *returnType = nullptr)
		{
			this->function = func;
			this->returnType = returnType;
			this->parameters = params;
		}

		virtual ~OverloadTemplate();
		Program * getProgram();
		bool matchByParameters(const std::vector<Type*> &paramTypes);
		virtual Function * createOverload(Function *func, const std::vector<Type*> &paramTypes) const = 0;

		inline size_t getParameterCount() const { return this->parameters.size(); }
		inline ParameterTemplate * getParameter(size_t index) { return this->parameters[index]; }
		inline void setParameters(const std::vector<ParameterTemplate*> &params) { this->parameters = params; }
		inline FunctionTemplate * getFunction()const { return this->function; }
		inline void setFunction(FunctionTemplate*f) { this->function = f; }

		ParameterTemplate * getThisParameter();

		inline Type *getReturnType() { return this->returnType; }
		inline void setReturnType(Type *returnType) { this->returnType = returnType; }
		inline SymbolTable * getSymbolTable() { return &this->symbolTable; }
	protected:
		std::vector<ParameterTemplate*> parameters;
		Type *returnType = nullptr;
		FunctionTemplate *function = nullptr;
		SymbolTable symbolTable;
	};
}