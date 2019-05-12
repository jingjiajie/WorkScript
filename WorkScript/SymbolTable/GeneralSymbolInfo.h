#pragma once

#include <Exception/Exception.h>
#include "SymbolInfo.h"

namespace WorkScript
{
    class GeneralSymbolInfo : public SymbolInfo
    {
    public:
        GeneralSymbolInfo(const GeneralSymbolInfo &ori) = default;

        GeneralSymbolInfo(const DebugInfo &d, const std::wstring &name, const std::vector<ValueDescriptor> &descs) noexcept
                : SymbolInfo(d, name), valueDescriptors(descs)
        {}

        GeneralSymbolInfo(const DebugInfo &d, const std::wstring &name, const ValueDescriptor &desc, const LinkageType &lt) noexcept
                : SymbolInfo(d, name), linkageType(lt)
        {
            this->valueDescriptors.push_back(desc);
        }

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
    protected:
        std::vector<ValueDescriptor> valueDescriptors;
        LinkageType linkageType = LinkageType::INTERNAL;
    };
}