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

	VariableInfo getVariableInfo(const std::string &varName);
	VariableInfo getLocalVariableInfo(const std::string &varName);
	VariableInfo addLocalVariable(const std::string &varName);
	const size_t getLocalVariableCount() const;
private:
	CompileContext * baseContext = nullptr;
	size_t localVariables = 0;
	std::unordered_map<std::string, size_t> variableOffsets;
};

