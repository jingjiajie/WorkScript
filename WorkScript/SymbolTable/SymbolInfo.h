#pragma once

#include <Type/Type.h>
#include "DeducedInfo.h"
#include "DebugInfo.h"

namespace WorkScript
{
    class InstantialContext;
    class Value;
    class GenerateContext;

    class SymbolInfo
    {
    public:
        SymbolInfo(const SymbolInfo &) = default;

        inline SymbolInfo(const DebugInfo &d, const std::wstring &name) noexcept
                : debugInfo(d), name(name)
        {}

        virtual ~SymbolInfo() noexcept = default;

        virtual SymbolInfo * clone() const noexcept = 0;
        virtual DeducedInfo deduce(InstantialContext *) const = 0;

//        virtual LinkageType getLinkageType() const = 0;
//        virtual void setLinkageType(const LinkageType &lt) noexcept = 0;

        inline std::wstring getName() const noexcept
        { return this->name; }

//        std::wstring getMangledName() const noexcept{
//            return this->mangledName;
//        }
//
//        void setMangledName(const std::wstring &name) noexcept{
//            this->mangledName = name;
//        }

        const DebugInfo &getDebugInfo() const noexcept
        {
            return this->debugInfo;
        }

        void setDebugInfo(const DebugInfo &debugInfo) noexcept
        {
            this->debugInfo = debugInfo;
        }
    protected:
        DebugInfo debugInfo;
        std::wstring name;
    };
}