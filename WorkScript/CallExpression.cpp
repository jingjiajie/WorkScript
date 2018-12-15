#include "stdafx.h"
#include "CallExpression.h"
#include "VariableExpression.h"
#include "UninvocableException.h"
#include "Program.h"
#include "MultiValueExpression.h"
#include "StringExpression.h"
#include "Overload.h"
#include "Utils.h"
#include "Function.h"

using namespace WorkScript;
using namespace std;

GenerateResult WorkScript::CallExpression::generateIR(GenerateContext * context)
{
	auto builder = context->getIRBuilder();
	return builder->CreateCall(overload->getLLVMFunction(context));
}

Type * CallExpression::getType() const
{
	return overload->getReturnType();
}

std::wstring CallExpression::toString() const
{
	auto leftStr = overload->getFunction()->getName();
	auto paramStr =  this->parameters->toString();
	return leftStr + L"(" + paramStr + L")";
}

ExpressionType CallExpression::getExpressionType() const
{
	return ExpressionType::FUNCTION_INVOCATION_EXPRESSION;
}

Expression * WorkScript::CallExpression::clone() const
{
	auto newInstance = new thistype(program, overload, parameters);
	return newInstance;
}

