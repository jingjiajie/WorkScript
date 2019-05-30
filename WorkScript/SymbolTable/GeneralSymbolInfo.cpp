#include "GeneralSymbolInfo.h"
#include "GenerateContext.h"

using namespace std;
using namespace WorkScript;

GenerateResult GeneralSymbolInfo::generateLLVMIR(GenerateContext *context) noexcept
{
    if(this->llvmValues.size() > 0) return this->llvmValues;
    auto builder = context->getIRBuilder();
    this->llvmValues.reserve(this->valueDescriptors.size());
    for(size_t i=0; i<this->valueDescriptors.size(); ++i){
        llvm::Type *llvmType = this->valueDescriptors[i].getType()->getLLVMType(context);
        llvm::Value *llvmVal = builder->CreateAlloca(llvmType);
        this->llvmValues.push_back(llvmVal);
    }
    return this->llvmValues;
}