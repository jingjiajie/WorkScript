#include "Program.h"
#include "Expression.h"
#include "Context.h"
#include "ExecuteCppCodeExpression.h"
#include "FunctionExpression.h"
#include "BooleanExpression.h"
#include "VariableExpression.h"
#include "StringExpression.h"
#include "AssignmentExpression.h"
#include <Windows.h>
#include <time.h>

using namespace std;

Program::Program()
{
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

void Program::pushAssignmentExpression(const char * const & varName, Expression * const & value)
{
	auto expr = new AssignmentExpression(new VariableExpression(varName, StorageLevel::LITERAL), value, StorageLevel::LITERAL);
	this->pushExpression(expr);
}

void Program::initConstants()
{
	this->pushAssignmentExpression("yes", &BooleanExpression::VAL_YES);
	this->pushAssignmentExpression("no", &BooleanExpression::VAL_NO);
	this->pushAssignmentExpression("true", &BooleanExpression::VAL_TRUE);
	this->pushAssignmentExpression("false", &BooleanExpression::VAL_FALSE);
}

void Program::initPrintExpression()
{
	FunctionExpression * printFunc = new FunctionExpression(StorageLevel::LITERAL);
	printFunc->setName("print");
	auto overload = new FunctionExpression::Overload;
	overload->setParameterNames({ "x" });
	overload->setImplement(new ExecuteCppCodeExpression([overload](Context *const& context)->Expression * {
		auto value = context->getLocalVariable(0);
		TempExpression<StringExpression> strExpr(value, value->toString(context));
		//转换为Unicode
		int len = MultiByteToWideChar(CP_UTF8, 0, strExpr->getValue(), -1, nullptr, 0);
		wchar_t *unicodeStr = new wchar_t[len + 1];
		MultiByteToWideChar(CP_UTF8, 0, strExpr->getValue(), -1, unicodeStr, len);
		//转换为本地编码
		len = WideCharToMultiByte(CP_ACP, 0, unicodeStr, -1, nullptr, 0, nullptr, nullptr);
		char *localStr = new char[len + 1];
		WideCharToMultiByte(CP_ACP, 0, unicodeStr, -1, localStr, len, nullptr, nullptr);
		cout << localStr;
		return &BooleanExpression::VAL_YES;
	}));
	printFunc->addOverload(overload);
	this->pushExpression(printFunc);
}