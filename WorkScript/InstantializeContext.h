#pragma once

namespace WorkScript {
	class SymbolTable;

	class InstantializeContext {
	public:
		inline InstantializeContext(SymbolTable *curSymbolTable) : currentSymbolTable(curSymbolTable) {}

		inline SymbolTable *getCurrentSymbolTable() { return this->currentSymbolTable; }
		inline void setCurrentSymbolTable(SymbolTable *symbolTable) { this->currentSymbolTable = symbolTable; }
	protected:
		SymbolTable * currentSymbolTable;
	};
}