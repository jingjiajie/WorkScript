#include "stdafx.h"
#include "CallExpression.h"
#include "VariableExpression.h"
#include "Program.h"
#include "MultiValueExpression.h"
#include "StringExpression.h"
#include "Overload.h"
#include "Utils.h"
#include "Function.h"

using namespace WorkScript;
using namespace std;

Expression * WorkScript::CallExpression::instantialize(InstantializeContext *context)
{
	throw WorkScriptException(L"非模板调用表达式无法实例化");
}

GenerateResult WorkScript::CallExpression::generateIR(GenerateContext * context)
{
	auto builder = context->getIRBuilder();
	return builder->CreateCall(bindOverload->getLLVMFunction(context));
}

Type * CallExpression::getType() const
{
	return bindOverload->getReturnType();
}

std::wstring CallExpression::toString() const
{
	auto leftStr = this->functionName;
	auto paramStr =  this->parameters->toString();
	return leftStr + L"(" + paramStr + L")";
}

ExpressionType CallExpression::getExpressionType() const
{
	return ExpressionType::CALL_EXPRESSION;
}

Expression * WorkScript::CallExpression::clone() const
{
	auto newInstance = new thistype(expressionInfo, functionName, this->bindOverload, parameters);
	newInstance->bindOverload = this->bindOverload;
	return newInstance;
}