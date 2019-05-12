#include "IntegerConstant.h"
#include "IntegerType.h"

using namespace WorkScript;
using namespace std;

DeducedInfo IntegerConstant::deduce(WorkScript::InstantialContext *context) const
{
	return ValueDescriptor(this->type, ValueKind::VALUE);
}

GenerateResult WorkScript::IntegerConstant::generateIR(GenerateContext * context)
{
	auto *myIntType = (IntegerType*)this->type;
	llvm::Type *llvmIntType = myIntType->getLLVMType(context);
	llvm::Value *llvmVal = llvm::ConstantInt::get(llvmIntType, llvm::APInt(myIntType->getLength(), this->value));
	return llvmVal;
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
