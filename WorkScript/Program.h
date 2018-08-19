#pragma once
#include <vector>

class Expression;
class Context;

class Program
{
public:
	Program();
	virtual ~Program();

	void execute();
	void compile();

	void pushExpression(Expression* const &);
	const std::vector<Expression*>& getExpressions() const;

protected:
	std::vector<Expression*> expressions;
	size_t localVariableCount = 0;

	void initPrintExpression();
};