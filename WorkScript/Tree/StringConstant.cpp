#include "StringConstant.h"
#include "Locales.h"
#include "StringCache.h"

using namespace WorkScript;

GenerateResult WorkScript::StringConstant::generateIR(GenerateContext * context)
{
    StringCache *cache = context->getStringCache();
    llvm::Value *val = cache->getCachedLLVMStringPtr(this->value);
    if(val){
        return val;
    }else{
        auto irBuilder = context->getIRBuilder();
        val = irBuilder->CreateGlobalStringPtr(Locales::fromWideChar(Encoding::ANSI, this->value));
        cache->cacheLLVMStringPtr(this->value, val);
        return val;
    }
}

std::wstring StringConstant::toString() const
{
	return L"\"" + this->value + L"\"";
}

Value * WorkScript::StringConstant::clone() const
{
	return new StringConstant(expressionInfo, this->value);
}

DeducedInfo StringConstant::deduce(WorkScript::InstantialContext *context) const
{
	return ValueDescriptor(PointerType::get(IntegerType::get(IntegerTypeClassification::CHAR),1), ValueKind::VALUE);
}

ExpressionType StringConstant::getExpressionType() const
{
    return ExpressionType::STRING;
}
