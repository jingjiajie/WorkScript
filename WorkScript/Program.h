#pragma once
#include <vector>
#include "Expression.h"

class Context;

class Program
{
public:
	Program();
	virtual ~Program();

	void execute();
	void compile();

	void pushExpression(const Pointer<Expression> &);
	const std::vector<Pointer<Expression>>& getExpressions() const;

protected:
	std::vector<Pointer<Expression>> expressions;
	size_t localVariableCount = 0;

	void pushAssignmentExpression(const wchar_t *const &varName,const Pointer<Expression> &value);

	void initConstants();
	void initPrintExpression();
};