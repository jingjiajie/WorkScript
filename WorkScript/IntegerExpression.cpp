#include "stdafx.h"
#include "IntegerExpression.h"
#include "Program.h"
#include "IntegerType.h"
#include "Utils.h"

using namespace std;
using namespace WorkScript;

inline WorkScript::IntegerExpression::IntegerExpression(Program *program,IntegerType *type, long long v)
	:Expression(program)
{
	this->value = v;
}

GenerateResult IntegerExpression::generateIR(GenerateContext * context)
{
	auto len = this->type->getLength();
	switch (len)
	{
	case 1:
		return (llvm::Value*)llvm::ConstantInt::get(llvm::Type::getInt8Ty(*context->getLLVMContext()), llvm::APInt(8, this->value));
	case 2:
		return (llvm::Value*)llvm::ConstantInt::get(llvm::Type::getInt16Ty(*context->getLLVMContext()), llvm::APInt(16, this->value));
	case 4:
		return (llvm::Value*)llvm::ConstantInt::get(llvm::Type::getInt32Ty(*context->getLLVMContext()), llvm::APInt(32, this->value));
	case 8:
		return (llvm::Value*)llvm::ConstantInt::get(llvm::Type::getInt64Ty(*context->getLLVMContext()), llvm::APInt(64, this->value));
	default:
		throw WorkScriptException(L"不支持的整数长度：" + to_wstring(len));
	}
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
	return new thistype(this->program, this->type, this->value);
}
