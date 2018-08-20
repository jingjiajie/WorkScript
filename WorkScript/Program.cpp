#include "Program.h"
#include "Expression.h"
#include "Context.h"
#include "ExecuteCppCodeExpression.h"
#include "FunctionExpression.h"
#include "BooleanExpression.h"
#include "VariableExpression.h"
#include "StringExpression.h"
#include <time.h>

using namespace std;

Program::Program()
{
	this->initPrintExpression();
}


Program::~Program()
{
	for (auto &lpExpr : this->expressions) {
		lpExpr->releaseLiteral();
	}
}

void Program::execute()
{
	Context context(this,this->localVariableCount);
	try {
		for (auto &expr : this->expressions) {
			expr->evaluate(&context)->releaseTemp();
		}
	}
	catch (WorkScriptException &ex)
	{
		cout << ex.what() << endl;
	}
	return;
}

void Program::compile()
{
	CompileContext context;
	for (auto &expr : this->expressions) {
		expr->compile(&context);
	}
	this->localVariableCount = context.getLocalVariableCount();
}

void Program::pushExpression(Expression* const &expr)
{
	this->expressions.push_back(expr);
}

const std::vector<Expression*>& Program::getExpressions() const
{
	return  this->expressions;
}

void Program::initPrintExpression()
{
	FunctionExpression * printFunc = new FunctionExpression(StorageLevel::LITERAL);
	printFunc->setName("print");
	auto overload = new FunctionExpression::Overload;
	overload->setParameterNames({ "x" });
	overload->setImplement(new ExecuteCppCodeExpression([overload](Context *const& context)->Expression * {
		auto value = context->getLocalVariable(0);
		auto strExpr = value->toString(context);
		cout << strExpr->getValue();
		strExpr->releaseTemp();
		return &BooleanExpression::YES;
	}));
	printFunc->addOverload(overload);
	this->pushExpression(printFunc);
}