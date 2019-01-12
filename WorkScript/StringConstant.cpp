#include "stdafx.h"
#include "StringConstant.h"
#include "Locale.h"

using namespace WorkScript;

GenerateResult WorkScript::StringConstant::generateLLVMIR(GenerateContext * context)
{
	auto irBuilder = context->getIRBuilder();
	return irBuilder->CreateGlobalStringPtr(Locale::unicodeToANSI(this->value.c_str()));
}

std::wstring WorkScript::StringConstant::toString() const
{
	return this->value;
}

Constant * WorkScript::StringConstant::clone() const
{
	return new StringConstant(this->value);
}

Type * WorkScript::StringConstant::getType()
{
	return PointerType::get(IntegerType::getSInt8Type(),1);
}
