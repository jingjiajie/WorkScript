#include "Program.h"
#include "Expression.h"
#include "Context.h"
#include "ExecuteCppCodeExpression.h"
#include "FunctionExpression.h"
#include "BooleanExpression.h"
#include "VariableExpression.h"
#include <time.h>
#include <memory>

using namespace std;

Program::Program()
{
	this->initPrintExpression();
}


Program::~Program()
{
}

void Program::execute()
{
	Context context(this->localVariableCount);
	for (auto &expr : this->expressions) {
		expr->evaluate(&context);
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

void Program::pushExpression(const shared_ptr<Expression> &expr)
{
	this->expressions.push_back(expr);
}

const std::vector<shared_ptr<Expression>>& Program::getExpressions() const
{
	return  this->expressions;
}

void Program::initPrintExpression()
{
	shared_ptr<FunctionExpression> printFunc(new FunctionExpression());
	printFunc->setFunctionName("print");
	shared_ptr<FunctionExpression::Overload> overload(new FunctionExpression::Overload);
	overload->setParameterNames({ "x" });
	overload->setImplement(shared_ptr<ExecuteCppCodeExpression>(new ExecuteCppCodeExpression([overload](Context *context)->std::shared_ptr<TermExpression> {
		shared_ptr<VariableExpression> varX(new VariableExpression("x"));
		cout << varX->evaluate(context)->toString();
		return BooleanExpression::YES;
	})));
	printFunc->addOverload(overload);
	this->pushExpression(printFunc);
}
