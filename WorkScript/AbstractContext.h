#pragma once
#include <string>
#include "SymbolTable.h"

namespace WorkScript {
	class AbstractContext {
	public:
		inline SymbolInfo * getSymbolInfo(const std::wstring &name) { return this->getAbstractSymbolTable()->getSymbolInfo(name); }
		inline SymbolInfo * setSymbol(const std::wstring &name, Type *type) { return this->getAbstractSymbolTable()->setSymbol(name, type); }

		virtual SymbolTable * getAbstractSymbolTable() = 0;
	};

	class CommonAbstractContext : public AbstractContext {
	public:
		virtual SymbolTable * getAbstractSymbolTable() override;
		inline size_t getBlockID() const { return this->blockID; }
	protected:
		size_t blockID = 0;
		SymbolTable abstractSymbolTable;
	};

	class BlockAbstractContext : public AbstractContext{
	public:
		BlockAbstractContext(size_t blockID)
			:blockID(blockID), abstractSymbolTable(BlockSymbolTable(blockID)) { }

		virtual BlockSymbolTable * getAbstractSymbolTable() override;
		inline size_t getBlockID() const { return this->blockID; }
	protected:
		size_t blockID = 0;
		BlockSymbolTable abstractSymbolTable;
	};
}