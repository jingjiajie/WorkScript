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

        ReferenceSymbolInfo(const ReferenceSymbolInfo &) = default;

        DeducedInfo deduce(InstantialContext *context) const override {
            return this->reference->deduce(context);
        }

        SymbolInfo * clone() const noexcept override{
            return new ReferenceSymbolInfo(*this);
        }
//
//        LinkageType getLinkageType() const override{
//            return this->reference->getLinkageType();
//        }

//        void setLinkageType(const LinkageType &lt) noexcept override{
//            this->reference->setLinkageType(lt);
//        }
    protected:
        SymbolInfo *reference = nullptr;
    };
}