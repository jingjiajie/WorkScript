#pragma once
#include "Type.h"
#include "DebugInfo.h"

namespace WorkScript
{
    class Value;
    class GenerateContext;

    class SymbolInfo
    {
    public:
        inline SymbolInfo(const DebugInfo &d, const std::wstring &name) noexcept
                : debugInfo(d), name(name)
        {}

        virtual ~SymbolInfo() noexcept = default;

        virtual Type *getType() const = 0;

        virtual LinkageType getLinkageType() const = 0;

        virtual Value *getValue() noexcept = 0;

        virtual void setValue(Value *value) noexcept = 0;

        virtual llvm::Value *getLLVMValue(const DebugInfo &d, GenerateContext *context) = 0;

        virtual llvm::Value *getLLVMValuePtr(const DebugInfo &d, GenerateContext *context) = 0;

        virtual void setLLVMValue(llvm::Value *llvmVal) noexcept = 0;

        virtual void setLLVMValuePtr(llvm::Value *llvmValPtr) noexcept = 0;

        virtual void setLinkageType(const LinkageType &lt) noexcept = 0;


        inline std::wstring getName() const noexcept
        { return this->name; }

        const DebugInfo &getDebugInfo() const noexcept
        {
            return this->debugInfo;
        }

        void setDebugInfo(const DebugInfo &debugInfo) noexcept
        {
            this->debugInfo = debugInfo;
        }

        virtual const Value *getValue() const noexcept
        {
            return const_cast<SymbolInfo *>(this)->getValue();
        }

    protected:
        DebugInfo debugInfo;
        std::wstring name;
    };
}