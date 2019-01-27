#include "StringConstant.h"
#include "Locales.h"

using namespace WorkScript;

GenerateResult WorkScript::StringConstant::generateIR(GenerateContext * context)
{
	auto irBuilder = context->getIRBuilder();
	return irBuilder->CreateGlobalStringPtr(Locales::fromWideChar(Encoding::ANSI, this->value.c_str()));
}

std::wstring WorkScript::StringConstant::toString() const
{
	return this->value;
}

Constant * WorkScript::StringConstant::clone() const
{
	return new StringConstant(expressionInfo, this->value);
}

Type * WorkScript::StringConstant::getType() const
{
	return PointerType::get(IntegerType::get(8),1);
}
