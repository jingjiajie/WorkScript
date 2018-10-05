#include "stdafx.h"
#include "FunctionInvocationExpression.h"
#include "VariableExpression.h"
#include "UninvocableException.h"
#include "Program.h"
#include "ParameterExpression.h"
#include "StringExpression.h"
#include "ParameterExpression.h"
#include "Overload.h"

using namespace WorkScript;
using namespace std;

FunctionInvocationExpression::~FunctionInvocationExpression()
{
}

//bool FunctionInvocationExpression::equals(Expression *target) const
//{
//	if (!target->getType(context)->equals(context, this->getType(context))) {
//		return false;
//	}
//	auto targetFunctionInvocationExpression = (const Pointer<FunctionInvocationExpression> &)(target);
//	if (!targetFunctionInvocationExpression->leftExpression->equals(context,this->leftExpression))return false;
//	if (!this->parameters->equals(context,targetFunctionInvocationExpression->parameters))return false;
//	return true;
//}

//const Pointer<FunctionExpression> FunctionInvocationExpression::getFunctionExpression(Context *const context) const
//{
//	Pointer<Expression> evaluatedLeft = this->leftExpression->evaluate(context);
//	if (!evaluatedLeft->getType(context)->equals(context, Type::FUNCTION_EXPRESSION)) {
//		Pointer<StringExpression> leftStrExpr = evaluatedLeft->toString(context);
//		wstring leftName(leftStrExpr->getValue());
//		wstring str = (leftName + L"²»ÊÇº¯Êý£¡");
//		throw std::move(UninvocableException(str.c_str()));
//	}
//	return evaluatedLeft;
//}

GenerateResult WorkScript::FunctionInvocationExpression::generateIR(GenerateContext * context)
{
	Overload *overload = this->program->getFunctionOverload(this->funcName, this->getParameterTypes());
	auto builder = context->getIRBuilder();
	return builder->CreateCall(overload->getLLVMFunction(context));
}

Type * FunctionInvocationExpression::getType() const
{
	this->program->getFunctionOverload(funcName, this->getParameterTypes());
}

std::wstring FunctionInvocationExpression::toString() const
{
	auto leftStr =  this->funcName;
	auto paramStr =  this->parameters->toString();
	return leftStr + L"(" + paramStr + L")";
}

ExpressionType FunctionInvocationExpression::getExpressionType() const
{
	return ExpressionType::FUNCTION_INVOCATION_EXPRESSION;
}

std::vector<Type*> WorkScript::FunctionInvocationExpression::getParameterTypes() const
{
	auto items = this->parameters->getItems();
	vector<Type*> paramTypes;
	paramTypes.reserve(items.size());
	for (size_t i = 0; i<items.size(); ++i)
	{
		paramTypes[i] = items[i]->getType();
	}
	return paramTypes;
}
