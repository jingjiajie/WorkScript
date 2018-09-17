#pragma once

#include <unordered_map>
#include <string>
#include "Pointer.h"
#include "CompileDomain.h"
#include "SymbolTable.h"

class Expression;

enum LinkTask {
	SYMBOL_COLLECTING, SYMBOL_BINDING
};

class LinkContext
{
public:
	LinkContext(SymbolTable *symbolTable, BLOCK_ID block, LinkTask task);
	LinkContext(LinkContext *baseContext, BLOCK_ID block);
	virtual ~LinkContext();

	SymbolTable *getSymbolTable();

	LinkTask getLinkTask()const;
	void setLinkTask(LinkTask task);
	BLOCK_ID getBlock()const;
private:
	LinkContext * baseContext = nullptr;
	SymbolTable * symbolTable = nullptr;
	BLOCK_ID block = 0;
	LinkTask task = SYMBOL_COLLECTING;
};