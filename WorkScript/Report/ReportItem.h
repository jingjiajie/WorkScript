#pragma once
#include <string>
#include "DebugInfo.h"

namespace WorkScript
{
    class ReportItem
    {
    public:
        ReportItem(const DebugInfo &d, const std::wstring &wmsg);

        const DebugInfo &getDebugInfo() const
        {
            return debugInfo;
        }

        void setDebugInfo(const DebugInfo &debugInfo)
        {
            this->debugInfo = debugInfo;
        }

        const std::wstring &getMessage() const
        {
            return message;
        }

        void setMessage(const std::wstring &message)
        {
            this->message = message;
        }

    private:
        DebugInfo debugInfo;
        std::wstring message;
    };
}