#include "FloatConstant.h"
#include "Type.h"

using namespace WorkScript;
using namespace std;

GenerateResult WorkScript::FloatConstant::generateIR(GenerateContext * context)
{
	auto *myFloatType = (FloatType*)this->type;
	llvm::Type *llvmFloatType = myFloatType->getLLVMType(context);
	llvm::Value *llvmVal = llvm::ConstantFP::get(llvmFloatType, this->value);
	return llvmVal;
}

std::wstring WorkScript::FloatConstant::toString() const
{
	return to_wstring(this->value);
}

Value * WorkScript::FloatConstant::clone() const
{
	return new FloatConstant(this->expressionInfo, type, value);
}

DeducedInfo FloatConstant::deduce(InstantialContext *context) const
{
	return ValueDescriptor(this->type,ValueKind::VALUE);
}

ExpressionType FloatConstant::getExpressionType() const
{
    return ExpressionType::FLOAT;
}
