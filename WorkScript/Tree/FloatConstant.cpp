#include "FloatConstant.h"
#include "Type.h"

using namespace WorkScript;
using namespace std;

GenerateResult WorkScript::FloatConstant::generateIR(GenerateContext * context)
{
	return (llvm::Value*)llvm::ConstantFP::get(this->type->getLLVMType(context), this->value);
}

std::wstring WorkScript::FloatConstant::toString() const
{
	return to_wstring(this->value);
}

Constant * WorkScript::FloatConstant::clone() const
{
	return new FloatConstant(this->expressionInfo, type, value);
}

Type * WorkScript::FloatConstant::getType() const
{
	return this->type;
}
