#pragma once
#include <vector>

namespace WorkScript {
	class SymbolTable;
	class SymbolInfo;
	class Type;

	class InstantializeContext {
	public:
		inline InstantializeContext() {};
		inline InstantializeContext(SymbolTable *abstractSymbolTable) 
			: abstractSymbolTable(abstractSymbolTable) {}

		inline InstantializeContext(SymbolTable *abstractSymbolTable, SymbolTable *instanceSymbolTable)
			: abstractSymbolTable(abstractSymbolTable), instanceSymbolTable(instanceSymbolTable) {}

		inline SymbolTable * getAbstractSymbolTable() { return this->abstractSymbolTable; }
		inline void setAbstractSymbolTable(SymbolTable *table) { this->abstractSymbolTable = table; }
		inline SymbolTable * getInstanceSymbolTable() { return this->instanceSymbolTable; }
		inline void setInstanceSymbolTable(SymbolTable *table) { this->instanceSymbolTable = table; }

		SymbolInfo * getSymbolInfo(const std::wstring &name);

	protected:
		SymbolTable * abstractSymbolTable = nullptr;
		SymbolTable * instanceSymbolTable = nullptr;
	};

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
	};
}