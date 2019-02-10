#pragma once
#include <string>
#include "DebugInfo.h"

namespace WorkScript
{
    class ReportItem
    {
    public:
        ReportItem(const DebugInfo &d, const std::wstring &wmsg) noexcept;

        const DebugInfo &getDebugInfo() const noexcept
        {
            return debugInfo;
        }

        void setDebugInfo(const DebugInfo &debugInfo) noexcept
        {
            this->debugInfo = debugInfo;
        }

        const std::wstring &getMessage() const noexcept
        {
            return message;
        }

        void setMessage(const std::wstring &message) noexcept
        {
            this->message = message;
        }

    private:
        DebugInfo debugInfo;
        std::wstring message;
    };
}
