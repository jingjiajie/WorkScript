#include "stdafx.h"
#include "IntegerExpression.h"
#include "DoubleExpression.h"
#include "ByteExpression.h"
#include "BooleanExpression.h"
#include "StringExpression.h"
#include "Program.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

GenerateResult IntegerExpression::generateIR(GenerateContext * context)
{
	return (llvm::Value*)llvm::ConstantInt::get(llvm::Type::getInt32Ty(*context->getLLVMContext()), llvm::APInt(32, this->value));
}

ExpressionType IntegerExpression::getExpressionType() const
{
	return ExpressionType::INTEGER_EXPRESSION;
}

std::wstring IntegerExpression::toString() const
{
	return to_wstring(this->value);
}

inline Type * WorkScript::IntegerExpression::getType() const
{
	return program->getType(TYPENAME_INTEGER);
}

Expression * WorkScript::IntegerExpression::clone() const
{
	return new thistype(this->value);
}
