#include "CompileContext.h"



CompileContext::CompileContext()
{
}

CompileContext::CompileContext(CompileContext * baseContext)
{
	this->baseContext = baseContext;
}


CompileContext::~CompileContext()
{
}

VariableInfo CompileContext::getVariableInfo(const wchar_t *const & varName)
{
	VariableInfo variableInfo;
	auto it = this->variableOffsets.find(varName);
	if (it != this->variableOffsets.end()) {
		variableInfo.found = true;
		variableInfo.upLevel = 0;
		variableInfo.offset = this->variableOffsets[varName];
	}
	else if (this->baseContext != nullptr) {
		variableInfo = this->baseContext->getVariableInfo(varName);
		variableInfo.upLevel++;
	}
	else {
		variableInfo.found = false;
	}
	return variableInfo;
}

VariableInfo CompileContext::getLocalVariableInfo(const wchar_t *const & varName)
{
	VariableInfo variableInfo;
	auto it = this->variableOffsets.find(varName);
	if (it != this->variableOffsets.end()) {
		variableInfo.found = true;
		variableInfo.upLevel = 0;
		variableInfo.offset = this->variableOffsets[varName];
	}
	else {
		variableInfo.found = false;
	}
	return variableInfo;
}

VariableInfo CompileContext::addLocalVariable(const wchar_t *const & varName)
{
	VariableInfo variableInfo;
	variableInfo.found = true;
	variableInfo.offset = this->localVariables;
	variableInfo.upLevel = 0;

	this->variableOffsets[varName] = variableInfo.offset;

	this->localVariables++;
	return variableInfo;
}

const size_t CompileContext::getLocalVariableCount() const
{
	return this->localVariables;
}
