#include "stdafx.h"
#include "StringExpression.h"
#include "Type.h"
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
	return new thistype(this->value);
}

std::wstring StringExpression::toString() const
{
	return this->value;
}

Type * StringExpression::getType() const
{
	return program->getType(TYPENAME_STRING);
}

GenerateResult StringExpression::generateIR(GenerateContext * context)
{
	return (llvm::Value*)context->getIRBuilder()->CreateGlobalStringPtr((char*)this->value.c_str());
}