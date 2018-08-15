#pragma once
#include <vector>
#include <memory>

class Expression;
class Context;

class Program
{
public:
	Program();
	virtual ~Program();

	void execute();
	void compile();

	void pushExpression(const std::shared_ptr<Expression> &);
	const std::vector<std::shared_ptr<Expression>>& getExpressions() const;

protected:
	std::vector<std::shared_ptr<Expression>> expressions;
	size_t localVariableCount = 0;

	void initPrintExpression();
};

