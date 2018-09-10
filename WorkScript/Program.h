#pragma once
#include <vector>
#include "Expression.h"

class Context;

class Program
{
public:
	Program();
	virtual ~Program();

	void execute(Context *context);
	void compile(CompileContext *context);

	void pushExpression(const Pointer<Expression> &);
	const std::vector<Pointer<Expression>>& getExpressions() const;

	void addIncludeFile(const wchar_t *filePath);
	std::vector<std::wstring> getIncludeFiles()const;

protected:
	std::vector<Pointer<Expression>> expressions;
	std::vector<std::wstring> includeFiles;

	void pushAssignmentExpression(const wchar_t *const &varName,const Pointer<Expression> &value);
	
};