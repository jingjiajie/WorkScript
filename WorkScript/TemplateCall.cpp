#include "stdafx.h"
#include "TemplateCall.h"
#include "CallExpression.h"
#include "MultiValueExpression.h"

using namespace WorkScript;
using namespace std;

Expression * WorkScript::TemplateCallExpression::instantialize(InstantializeContext * context)
{
	Overload *overload = getProgram()->getFunctionOverload(functionName, parameters->getTypes());
	return new CallExpression(expressionInfo, functionName, overload, parameters->instantialize(context));
}

GenerateResult WorkScript::TemplateCallExpression::generateIR(GenerateContext * context)
{
	throw WorkScriptException(L"模板表达式不能生成字节码！");
}

Type * WorkScript::TemplateCallExpression::getType() const
{
	return this->bindOverloadTemplate->getReturnType();
}

std::wstring WorkScript::TemplateCallExpression::toString() const
{
	return this->functionName;
}

ExpressionType WorkScript::TemplateCallExpression::getExpressionType() const
{
	return ExpressionType::TEMPLATE_CALL_EXPRESSION;
}

Expression * WorkScript::TemplateCallExpression::clone() const
{
	return new TemplateCallExpression(expressionInfo, this->functionName, bindOverloadTemplate, this->parameters->clone());
}
