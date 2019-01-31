#include "UnaryOperator.h"
#include "Type.h"
#include "Function.h"

using namespace WorkScript;

UnaryOperator::~UnaryOperator()
{
	delete this->subExpression;
}

std::wstring WorkScript::UnaryOperator::toString() const
{
	return this->getOperatorString() + this->subExpression->toString();
}

Type * WorkScript::UnaryOperator::getType(InstantialContext *context) const
{
	return this->subExpression->getType(context);
}

Expression * WorkScript::UnaryOperator::clone() const
{
	return new UnaryOperator(expressionInfo, subExpression, operatorType);
}

GenerateResult WorkScript::UnaryOperator::generateIR(GenerateContext * context)
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
		throw InternalError(this->expressionInfo.getDebugInfo(), L"未知的单目运算符");
	}

	return res;
}

ExpressionType WorkScript::UnaryOperator::getExpressionType() const
{
	return ExpressionType::UNARY_OPERATOR_EXPRESSION;
}

std::wstring WorkScript::UnaryOperator::getOperatorString() const
{
	switch (this->operatorType)
	{
	case OperatorType::NEGATIVE:
		return L"-";
	case OperatorType::NOT:
		return L"!";
	default:
		throw InternalError(this->expressionInfo.getDebugInfo(), L"未知的单目运算符");
	}
}
