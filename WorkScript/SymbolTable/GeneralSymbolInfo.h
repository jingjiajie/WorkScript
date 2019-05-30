#pragma once

#include <vector>
#include "Exception.h"
#include "SymbolInfo.h"

namespace WorkScript
{
    class GeneralSymbolInfo : public SymbolInfo
    {
    public:
        GeneralSymbolInfo(const GeneralSymbolInfo &ori) = default;

        GeneralSymbolInfo(const DebugInfo &d, const std::wstring &name, const std::vector<ValueDescriptor> &descs, const std::vector<llvm::Value*> &llvmVals = {}) noexcept
                : SymbolInfo(d, name), valueDescriptors(descs), llvmValues(llvmVals)
        {}

        GeneralSymbolInfo(const DebugInfo &d, const std::wstring &name, const ValueDescriptor &desc, const LinkageType &lt, llvm::Value *llvmVal = nullptr) noexcept
                : SymbolInfo(d, name), linkageType(lt)
        {
            this->valueDescriptors.push_back(desc);
            if(llvmVal) this->llvmValues.push_back(llvmVal);
        }

        GenerateResult generateLLVMIR(GenerateContext *context) noexcept override;

        SymbolInfo * clone() const noexcept override{
            return new GeneralSymbolInfo(*this);
        }

//        inline GeneralSymbolInfo(const DebugInfo &d, const std::wstring &name, const ValueDescriptor &desc, const LinkageType &lt,
//                                 llvm::Value *llvmValue) noexcept
//                : SymbolInfo(d, name), valueDescriptor(desc), linkageType(lt), llvmValue(llvmValue)
//        {}

        DeducedInfo deduce(InstantialContext *) const override
        {
            return this->valueDescriptors;
        }

//        LinkageType getLinkageType() const override
//        { return this->linkageType; }
//
//        void setLinkageType(const LinkageType &lt) noexcept override
//        { this->linkageType = lt; }

        void setLLVMValues(const std::vector<llvm::Value*> &llvmVals) noexcept
        {
            this->llvmValues = llvmVals;
        }

        void setLLVMValue(llvm::Value *llvmVal) noexcept
        {
            this->llvmValues.clear();
            this->llvmValues.push_back(llvmVal);
        }
    protected:
        std::vector<ValueDescriptor> valueDescriptors;
        LinkageType linkageType = LinkageType::INTERNAL;
        std::vector<llvm::Value*> llvmValues;
    };
}