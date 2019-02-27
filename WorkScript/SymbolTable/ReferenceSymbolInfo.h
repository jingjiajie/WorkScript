#pragma once
#include "SymbolInfo.h"

namespace WorkScript
{
    class ReferenceSymbolInfo : public SymbolInfo
    {
    public:
        ReferenceSymbolInfo(const DebugInfo &d, const std::wstring &name, SymbolInfo *ref)
                : SymbolInfo(d, name), reference(ref)
        {}

        Type *getType() const override {
            return this->reference->getType();
        }

        LinkageType getLinkageType() const override{
            return this->reference->getLinkageType();
        }

        Value *getValue() noexcept override{
            return this->reference->getValue();
        }

        void setValue(Value *value) noexcept override{
            this->reference->setValue(value);
        }

        llvm::Value *getLLVMValue(const DebugInfo &d, GenerateContext *context) override{
            return this->reference->getLLVMValue(d, context);
        }

        llvm::Value *getLLVMValuePtr(const DebugInfo &d, GenerateContext *context) override{
            return this->reference->getLLVMValuePtr(d, context);
        }

        void setLLVMValue(llvm::Value *llvmVal) noexcept override{
            this->reference->setLLVMValue(llvmVal);
        };

        void setLLVMValuePtr(llvm::Value *llvmValPtr) noexcept override{
            this->reference->setLLVMValuePtr(llvmValPtr);
        }

        void setLinkageType(const LinkageType &lt) noexcept override{
            this->reference->setLinkageType(lt);
        }
    protected:
        SymbolInfo *reference = nullptr;
    };
}