#pragma once
#include "SymbolInfo.h"

namespace WorkScript
{
    class GeneralSymbolInfo : public SymbolInfo
    {
    public:
        inline GeneralSymbolInfo(const DebugInfo &d, const std::wstring &name, Type *type,const LinkageType &lt,
                                 Value *value = nullptr) noexcept
                : SymbolInfo(d, name), type(type), value(value), linkageType(lt)
        {}

        inline GeneralSymbolInfo(const DebugInfo &d, const std::wstring &name, Type *type,const LinkageType &lt,
                                 llvm::Value *llvmValue) noexcept
                : SymbolInfo(d, name), type(type), linkageType(lt), llvmValue(llvmValue)
        {}

        ~GeneralSymbolInfo() override;

        llvm::Value *getLLVMValue(const DebugInfo &d, GenerateContext *context) override;

        llvm::Value *getLLVMValuePtr(const DebugInfo &d, GenerateContext *context) override;

        void setValue(Value *value) noexcept override;

        const Value *getValue() const noexcept override
        { return this->value; }

        Value *getValue() noexcept override
        { return this->value; }

        void setLLVMValue(llvm::Value *llvmVal) noexcept override
        { this->llvmValue = llvmVal; }

        void setLLVMValuePtr(llvm::Value *llvmValPtr) noexcept override
        { this->llvmValuePtr = llvmValPtr; }

        Type *getType() const override
        { return this->type; }

        LinkageType getLinkageType() const override
        { return this->linkageType; }

        void setLinkageType(const LinkageType &lt) noexcept override
        { this->linkageType = lt; }
    protected:
        Type *type = nullptr;
        Value *value = nullptr;
        LinkageType linkageType = LinkageType::INTERNAL;
        llvm::Value *llvmValue = nullptr;
        llvm::Value *llvmValuePtr = nullptr;
    };
}