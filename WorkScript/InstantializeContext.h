#pragma once
#include <vector>

namespace WorkScript {
	class SymbolTable;
	class SymbolInfo;
	class Type;

	class InstantializeContext {
	public:
		inline InstantializeContext(size_t branchID) :branchID(branchID) {}
		inline InstantializeContext(size_t branchID, SymbolTable *abstractSymbolTable)
			: abstractSymbolTable(abstractSymbolTable), branchID(branchID) {}

		inline InstantializeContext(size_t blockID, SymbolTable *abstractSymbolTable, SymbolTable *instanceSymbolTable)
			: abstractSymbolTable(abstractSymbolTable), instanceSymbolTable(instanceSymbolTable), branchID(branchID) {}

		inline SymbolTable * getAbstractSymbolTable() { return this->abstractSymbolTable; }
		inline void setAbstractSymbolTable(SymbolTable *table) { this->abstractSymbolTable = table; }
		inline SymbolTable * getInstanceSymbolTable() { return this->instanceSymbolTable; }
		inline void setInstanceSymbolTable(SymbolTable *table) { this->instanceSymbolTable = table; }
		inline void setBranchID(size_t branchID) { this->branchID = branchID; }
		inline size_t getBranchID()const { return this->branchID; }
		SymbolInfo * getSymbolInfo(const std::wstring &name);

	protected:
		SymbolTable * abstractSymbolTable = nullptr;
		SymbolTable * instanceSymbolTable = nullptr;
		size_t branchID = 0;
	};
/*
	class FunctionInstantializeContext : public InstantializeContext{
	public:
		using InstantializeContext::InstantializeContext;
		FunctionInstantializeContext(SymbolTable *abstractSymbolTable, SymbolTable *instanceSymbolTable, const std::vector<Type*> &realParamTypes)
			:InstantializeContext(abstractSymbolTable, instanceSymbolTable), realParameterTypes(realParamTypes) { }
		FunctionInstantializeContext(const std::vector<Type*> &realParamTypes) 
			:realParameterTypes(realParamTypes)	{ }

		std::vector<Type*> getRealParameterTypes();
	protected:
		std::vector<Type*> realParameterTypes;
	};*/
}