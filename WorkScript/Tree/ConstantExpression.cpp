#include "ConstantExpression.h"

using namespace WorkScript;
using namespace std;

WorkScript::ConstantExpression::~ConstantExpression()
{
	delete this->value;
}

std::wstring WorkScript::ConstantExpression::toString() const
{
	return this->value->toString();
}

Type * WorkScript::ConstantExpression::getType(InstantializeContext * context) const
{
	return this->value->getType();
}

GenerateResult WorkScript::ConstantExpression::generateIR(GenerateContext * context)
{
	return this->value->generateLLVMIR(context);
}

ExpressionType WorkScript::ConstantExpression::getExpressionType() const
{
	return ExpressionType::CONSTANT_EXPRESSION;
}

Expression * WorkScript::ConstantExpression::clone() const
{
	return new ConstantExpression(expressionInfo, this->value->clone());
}
