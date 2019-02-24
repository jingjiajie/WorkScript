#include "IntegerConstant.h"
#include "IntegerType.h"

using namespace WorkScript;
using namespace std;

Type * WorkScript::IntegerConstant::getType() const noexcept
{
	return this->type;
}

GenerateResult WorkScript::IntegerConstant::generateIR(GenerateContext * context)
{
	auto *myIntType = (IntegerType*)this->type;
	return (llvm::Value*)llvm::ConstantInt::get(myIntType->getLLVMType(context), llvm::APInt(myIntType->getLength(), this->value));
}

std::wstring WorkScript::IntegerConstant::toString() const
{
	return to_wstring(this->value);
}

Value * WorkScript::IntegerConstant::clone() const
{
	return new IntegerConstant(expressionInfo, type, value);
}

ExpressionType IntegerConstant::getExpressionType() const
{
    return ExpressionType::INTEGER;
}
