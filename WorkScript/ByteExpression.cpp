#include "stdafx.h"
#include "ByteExpression.h"
#include "DoubleExpression.h"
#include "IntegerExpression.h"
#include "BooleanExpression.h"
#include "StringExpression.h"
#include "UncalculatableException.h"
#include "Program.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

GenerateResult WorkScript::ByteExpression::generateIR(GenerateContext * context)
{
	return (llvm::Value*)llvm::ConstantInt::get(llvm::Type::getInt8Ty(*context->getLLVMContext()), llvm::APInt(8, this->value));
}

ExpressionType ByteExpression::getExpressionType() const
{
	return ExpressionType::BYTE_EXPRESSION;
}

std::wstring ByteExpression::toString() const
{
	return to_wstring(this->value);
}

Expression * WorkScript::ByteExpression::clone() const
{
	return new thistype(this->value);
}

Type * WorkScript::ByteExpression::getType() const
{
	return program->getType(TYPENAME_BYTE);
}