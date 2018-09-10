#include "MainProgram.h"
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

MainProgram::MainProgram()
{
	this->initConstants();
	this->initPrintExpression();
}


MainProgram::~MainProgram()
{
}


void MainProgram::initConstants()
{

}

void MainProgram::initPrintExpression()
{
	Pointer<FunctionExpression> printFunc = new FunctionExpression();
	printFunc->setName(L"print");
	auto overload = new Overload;
	ParameterInfo *paramInfos = new ParameterInfo[1];
	paramInfos[0].setParameterName(L"x");
	paramInfos[0].setVarargs(true);
	overload->setParameterInfos(paramInfos, 1);
	overload->setImplement(new ExecuteCppCodeExpression([overload](Context *const& context)->Pointer<Expression> {
		auto value = context->getStackFrame()->getLocalVariable(0);
		Pointer<StringExpression> strExpr = value->toString(context);
		wprintf(L"%ls", strExpr->getValue());
		return BooleanExpression::VAL_OK;
	}));
	printFunc->addOverload(overload);
	this->pushExpression(printFunc);
}