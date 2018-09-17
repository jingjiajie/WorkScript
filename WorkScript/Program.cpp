#include "Program.h"
#include "Expression.h"
#include "Context.h"
#include "ExecuteCppCodeExpression.h"
#include "FunctionExpression.h"
#include "BooleanExpression.h"
#include "VariableExpression.h"
#include "StringExpression.h"
#include "AssignmentExpression.h"
#include "CallStack.h"
#include "StackFrame.h"
#include <locale.h>
#include <time.h>
#include <wchar.h>

using namespace std;

Program::Program()
{

}


Program::~Program()
{
}

void Program::printProgram()const
{
	for (auto &expr : this->expressions) {
		auto strExpr = expr->toString(nullptr);
		wprintf(L"%s\n", strExpr->getValue());
	}
}

void Program::execute(Context *context) //throws WorkScriptException
{
	for (auto &expr : this->expressions) {
		expr->evaluate(context);
	}
	return;
}

void Program::link(LinkContext *context)
{
	for (auto &expr : this->expressions) {
		expr->link(context);
	}
}

void Program::pushExpression(const Pointer<Expression> &expr)
{
	this->expressions.push_back(expr);
}

const std::vector<Pointer<Expression>>& Program::getExpressions() const
{
	return this->expressions;
}

void Program::addIncludeFile(const wchar_t * filePath)
{
	this->includeFiles.push_back(filePath);
}

std::vector<std::wstring> Program::getIncludeFiles() const
{
	return this->includeFiles;
}

void Program::pushAssignmentExpression(const wchar_t * const & varName, const Pointer<Expression> & value)
{
	auto expr = new AssignmentExpression(new VariableExpression(varName), value);
	this->pushExpression(expr);
}
