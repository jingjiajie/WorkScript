#include "stdafx.h"
#include "StringExpression.h"
#include "IntegerPointerType.h"
#include "Program.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

ExpressionType StringExpression::getExpressionType() const
{
	return ExpressionType::STRING_EXPRESSION;
}

Expression * WorkScript::StringExpression::clone() const
{
	return new thistype(expressionInfo, this->value);
}

Expression * WorkScript::StringExpression::instantialize(InstantializeContext *context)
{
	return this->clone();
}

std::wstring StringExpression::toString() const
{
	return this->value;
}

Type * StringExpression::getType() const
{
	return this->getProgram()->getUInt8PtrType();
}

GenerateResult StringExpression::generateIR(GenerateContext * context)
{
	auto irBuilder = context->getIRBuilder();
	return irBuilder->CreateGlobalStringPtr((char*)this->value.c_str());
}