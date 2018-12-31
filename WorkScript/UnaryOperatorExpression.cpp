#include "stdafx.h"
#include "UnaryOperatorExpression.h"
#include "Type.h"
#include "Function.h"

using namespace WorkScript;

UnaryOperatorExpression::~UnaryOperatorExpression()
{
	delete this->subExpression;
}

std::wstring WorkScript::UnaryOperatorExpression::toString() const
{
	return this->getOperatorString() + this->subExpression->toString();
}

Type * WorkScript::UnaryOperatorExpression::getType(InstantializeContext *context) const
{
	return this->subExpression->getType(context);
}

Expression * WorkScript::UnaryOperatorExpression::clone() const
{
	return new UnaryOperatorExpression(expressionInfo, subExpression, operatorType);
}

GenerateResult WorkScript::UnaryOperatorExpression::generateIR(GenerateContext * context)
{
	auto irBuilder = context->getIRBuilder();
	llvm::Value *subValue = this->subExpression->generateIR(context).getValue();
	llvm::Value *res;
	switch (this->operatorType)
	{
	case OperatorType::NEGATIVE:
		res = irBuilder->CreateNeg(subValue);
		break;
	case OperatorType::NOT:
		res = irBuilder->CreateNot(subValue);
		break;
	default:
		throw WorkScriptException(L"未知的单目运算符");
	}

	return res;
}

ExpressionType WorkScript::UnaryOperatorExpression::getExpressionType() const
{
	return ExpressionType::UNARY_OPERATOR_EXPRESSION;
}

std::wstring WorkScript::UnaryOperatorExpression::getOperatorString() const
{
	switch (this->operatorType)
	{
	case OperatorType::NEGATIVE:
		return L"-";
	case OperatorType::NOT:
		return L"!";
	default:
		throw WorkScriptException(L"未知的单目运算符");
	}
}
