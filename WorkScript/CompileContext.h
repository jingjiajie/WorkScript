#pragma once

#include <unordered_map>
#include <string>
#include "Pointer.h"
#include "VariableCompileInfo.h"

class Expression;

class CompileContext
{
public:
	CompileContext();
	CompileContext(CompileContext *baseContext);
	virtual ~CompileContext();

	bool getVariableInfo(const wchar_t *varName, VariableCompileInfo *const outVariableCompileInfo);
	bool getBaseVariableInfo(const wchar_t *varName, VariableCompileInfo *const outVariableCompileInfo);
	bool getLocalVariableInfo(const wchar_t *varName, VariableCompileInfo *const outVariableCompileInfo);
	void addLocalVariable(const wchar_t *varName, VariableCompileInfo *const outVariableCompileInfo);
	const size_t getLocalVariableCount() const;
private:
	CompileContext * baseContext = nullptr;
	size_t localVariables = 0;
	std::unordered_map<std::wstring, size_t> variableOffsets;
	int depth = 0;
};