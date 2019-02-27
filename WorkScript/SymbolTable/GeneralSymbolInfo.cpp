#include "GeneralSymbolInfo.h"
#include "GenerateContext.h"
#include "Value.h"
#include "Locales.h"

using namespace std;
using namespace WorkScript;

GeneralSymbolInfo::~GeneralSymbolInfo()
{
    delete this->value;
}

void GeneralSymbolInfo::setValue(WorkScript::Value *value) noexcept
{
    delete this->value;
    this->value = value;
}

llvm::Value * GeneralSymbolInfo::getLLVMValue(const DebugInfo &d, GenerateContext * context)
{
    if (this->llvmValue) {
        return this->llvmValue;
    }
    else {
        auto builder = context->getIRBuilder();
        auto llvmVal = builder->CreateLoad(this->getLLVMValuePtr(d, context));
        this->llvmValue = llvmVal;
        return llvmVal;
    }
}

llvm::Value * GeneralSymbolInfo::getLLVMValuePtr(const DebugInfo &d, GenerateContext * context)
{
    if (!this->llvmValuePtr)
    {
        if(this->llvmValue){
            d.getReport()->error(UnassignableError(d, L"变量"+this->name+L"不可赋值！"), ErrorBehavior::CANCEL_EXPRESSION);
        }
        auto builder = context->getIRBuilder();
        this->llvmValuePtr = builder->CreateAlloca(this->type->getLLVMType(context), nullptr, Locales::fromWideChar(Encoding::ANSI, this->name));
    }
    return this->llvmValuePtr;
}

