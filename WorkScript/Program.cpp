#include "Program.h"
#include "Expression.h"
#include "Context.h"
#include "ExecuteCppCodeExpression.h"
#include "FunctionExpression.h"
#include "BooleanExpression.h"
#include "VariableExpression.h"
#include "StringExpression.h"
#include "AssignmentExpression.h"
#include <locale.h>
#include <time.h>
#include <wchar.h>

using namespace std;

Program::Program()
{
	this->initConstants();
	this->initPrintExpression();
}


Program::~Program()
{
}

void Program::execute()
{
	Context context(this,this->localVariableCount);
	try {
		for (auto &expr : this->expressions) {
			expr->evaluate(&context);
		}
	}
	catch (const WorkScriptException &ex)
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

void Program::pushExpression(const Pointer<Expression> &expr)
{
	this->expressions.push_back(expr);
}

const std::vector<Pointer<Expression>>& Program::getExpressions() const
{
	return this->expressions;
}

void Program::pushAssignmentExpression(const wchar_t * const & varName, const Pointer<Expression> & value)
{
	auto expr = new AssignmentExpression(new VariableExpression(varName), value);
	this->pushExpression(expr);
}

void Program::initConstants()
{

}

void Program::initPrintExpression()
{
	Pointer<FunctionExpression> printFunc = new FunctionExpression();
	printFunc->setName(L"print");
	auto overload = new Overload;
	ParameterInfo *paramInfos = new ParameterInfo[1];
	paramInfos[0].setParameterName(L"x");
	overload->setParameterInfos(paramInfos, 1);
	overload->setImplement(new ExecuteCppCodeExpression([overload](Context *const& context)->Pointer<Expression> {
		auto value = context->getLocalVariable(0);
		Pointer<StringExpression> strExpr =  value->toString(context);
		wprintf(L"%ls", strExpr->getValue());
		return BooleanExpression::VAL_OK;
	}));
	printFunc->addOverload(overload);
	this->pushExpression(printFunc);
}