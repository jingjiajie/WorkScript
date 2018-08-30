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
	setlocale(LC_CTYPE, "");
	this->initConstants();
	this->initPrintExpression();
}


Program::~Program()
{
	for (size_t i = 0; i < this->expressions.size(); ++i) {
		this->expressions[i]->releaseLiteral();
	}
}

void Program::execute()
{
	Context context(this,this->localVariableCount);
	try {
		for (auto &expr : this->expressions) {
			auto ret = expr->evaluate(&context);
			ret->releaseTemp();
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

void Program::pushAssignmentExpression(const wchar_t * const & varName, Expression * const & value)
{
	auto expr = new AssignmentExpression(new VariableExpression(varName, StorageLevel::LITERAL), value, StorageLevel::LITERAL);
	this->pushExpression(expr);
}

void Program::initConstants()
{
	this->pushAssignmentExpression(L"true", &BooleanExpression::VAL_TRUE);
	this->pushAssignmentExpression(L"yes", &BooleanExpression::VAL_YES);
	this->pushAssignmentExpression(L"ok", &BooleanExpression::VAL_OK);
	this->pushAssignmentExpression(L"good", &BooleanExpression::VAL_GOOD);

	this->pushAssignmentExpression(L"false", &BooleanExpression::VAL_FALSE);
	this->pushAssignmentExpression(L"no", &BooleanExpression::VAL_NO);
	this->pushAssignmentExpression(L"bad", &BooleanExpression::VAL_BAD);
}

void Program::initPrintExpression()
{
	FunctionExpression * printFunc = new FunctionExpression(StorageLevel::LITERAL);
	printFunc->setName(L"print");
	auto overload = new Overload;
	ParameterInfo *paramInfos = new ParameterInfo[1];
	paramInfos[0].setParameterName(L"x");
	overload->setParameterInfos(paramInfos, 1);
	overload->setImplement(new ExecuteCppCodeExpression([overload](Context *const& context)->Expression * {
		auto value = context->getLocalVariable(0);
		TempExpression<StringExpression> strExpr(value, value->toString(context));
		wprintf(L"%ls", strExpr->getValue());
		return &BooleanExpression::VAL_YES;
	}));
	printFunc->addOverload(overload);
	this->pushExpression(printFunc);
}