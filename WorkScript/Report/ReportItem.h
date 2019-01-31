#pragma once
#include <string>
#include "DebugInfo.h"

namespace WorkScript
{
    class ReportItem
    {
    public:
        ReportItem(const DebugInfo &d, const std::wstring &wmsg)
                : debugInfo(d)
        {
            std::wstring str = L"第" + std::to_wstring(d.getLocation().getLine()) + L"行，第" +
                               std::to_wstring(d.getLocation().getColumn()) + L"列：" + wmsg;
            this->setMessage(str);
        }

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