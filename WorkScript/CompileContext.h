#pragma once

#include <unordered_map>
#include <string>
#include "VariableInfo.h"

class CompileContext
{
public:
	CompileContext();
	CompileContext(CompileContext *baseContext);
	virtual ~CompileContext();

	VariableInfo getVariableInfo(const wchar_t *const &varName);
	VariableInfo getLocalVariableInfo(const wchar_t *const&varName);
	VariableInfo addLocalVariable(const wchar_t *const&varName);
	const size_t getLocalVariableCount() const;
private:
	CompileContext * baseContext = nullptr;
	size_t localVariables = 0;
	std::unordered_map<std::wstring, size_t> variableOffsets;
};

