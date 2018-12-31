#include "stdafx.h"
#include "IntegerConstant.h"
#include "IntegerType.h"

using namespace WorkScript;
using namespace std;

Type * WorkScript::IntegerConstant::getType()
{
	return this->type;
}

GenerateResult WorkScript::IntegerConstant::generateLLVMIR(GenerateContext * context)
{
	IntegerType *myIntType = (IntegerType*)this->type;
	return (llvm::Value*)llvm::ConstantInt::get(myIntType->getLLVMType(context), llvm::APInt(myIntType->getLength(), this->value));
}

std::wstring WorkScript::IntegerConstant::toString() const
{
	return to_wstring(this->value);
}

Constant * WorkScript::IntegerConstant::clone() const
{
	return new IntegerConstant(type, value);
}
