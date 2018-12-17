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

Expression * WorkScript::CallExpression::instantialize()
{
	//TODO 实例化要返回新的对象
	Overload *overload = this->program->getFunctionOverload(this->functionName, this->parameters->getTypes());
	if (!overload) {
		throw WorkScriptException(L"无法找到" + this->functionName + L"(" + this->parameters->toString() + L")");
	}
	this->bindOverload = overload;
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
	return ExpressionType::FUNCTION_INVOCATION_EXPRESSION;
}

Expression * WorkScript::CallExpression::clone() const
{
	auto newInstance = new thistype(EXPRESSION_MEMBERS, functionName, parameters);
	newInstance->bindOverload = this->bindOverload;
	return newInstance;
}

