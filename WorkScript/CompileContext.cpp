#include "CompileContext.h"



CompileContext::CompileContext()
{
}

CompileContext::CompileContext(CompileContext * baseContext)
{
	this->baseContext = baseContext;
	this->depth = baseContext->depth + 1;
}


CompileContext::~CompileContext()
{
}

bool CompileContext::getVariableInfo(const wchar_t *const & varName, VariableCompileInfo *const outVariableCompileInfo)
{
	if (this->getLocalVariableInfo(varName, outVariableCompileInfo)) {
		return true;
	}
	else {
		return this->getBaseVariableInfo(varName, outVariableCompileInfo);
	}
}

bool CompileContext::getBaseVariableInfo(const wchar_t * const & varName, VariableCompileInfo * const outVariableCompileInfo)
{
	if (this->baseContext == nullptr) {
		return false;
	}
	else {
		return this->baseContext->getVariableInfo(varName,outVariableCompileInfo);
	}
}

bool CompileContext::getLocalVariableInfo(const wchar_t *const & varName, VariableCompileInfo *const outVariableCompileInfo)
{
	auto it = this->variableOffsets.find(varName);
	if (it != this->variableOffsets.end()) {
		outVariableCompileInfo->depth = this->depth;
		outVariableCompileInfo->offset = this->variableOffsets[varName];
		return true;
	}
	else {
		return false;
	}
}

void CompileContext::addLocalVariable(const wchar_t *const & varName, VariableCompileInfo *const outVariableCompileInfo)
{
	outVariableCompileInfo->offset = this->localVariables;
	outVariableCompileInfo->depth = this->depth;

	this->variableOffsets[varName] = outVariableCompileInfo->offset;

	this->localVariables++;
}

const size_t CompileContext::getLocalVariableCount() const
{
	return this->localVariables;
}
