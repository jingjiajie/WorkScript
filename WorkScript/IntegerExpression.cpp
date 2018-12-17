#include "stdafx.h"
#include "IntegerExpression.h"
#include "Program.h"
#include "IntegerType.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

inline WorkScript::IntegerExpression::IntegerExpression(EXPRESSION_CTOR_FORMAL_PARAMS,IntegerType *type, long long v)
	:EXPRESSION_CTOR_CALL,type(type),value(v)
{

}

Expression * WorkScript::IntegerExpression::instantialize()
{
	return this->clone();
}

GenerateResult IntegerExpression::generateIR(GenerateContext * context)
{
	return (llvm::Value*)llvm::ConstantInt::get(this->type->getLLVMType(context), llvm::APInt(this->type->getLength(), this->value));
}

ExpressionType IntegerExpression::getExpressionType() const
{
	return ExpressionType::INTEGER_EXPRESSION;
}

std::wstring IntegerExpression::toString() const
{
	return to_wstring(this->value);
}

IntegerType * WorkScript::IntegerExpression::getType() const
{
	return this->type;
}

Expression * WorkScript::IntegerExpression::clone() const
{
	return new thistype(EXPRESSION_MEMBERS, this->type, this->value);
}
