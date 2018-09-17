#include "LinkContext.h"
#include "CompileDomain.h"

using namespace std;

LinkContext::LinkContext(SymbolTable * symbolTable, BLOCK_ID block, LinkTask task)
{
	this->symbolTable = symbolTable;
	this->block = block;
	this->setLinkTask(task);
}

LinkContext::LinkContext(LinkContext * baseContext, BLOCK_ID block)
{
	this->baseContext = baseContext;
	this->symbolTable = baseContext->symbolTable;
	this->block = block;
	this->task = baseContext->task;
}


LinkContext::~LinkContext()
{
}

SymbolTable * LinkContext::getSymbolTable()
{
	return this->symbolTable;
}

LinkTask LinkContext::getLinkTask() const
{
	return this->task;
}

void LinkContext::setLinkTask(LinkTask task)
{
	this->task = task;
}

BLOCK_ID LinkContext::getBlock() const
{
	return this->block;
}
