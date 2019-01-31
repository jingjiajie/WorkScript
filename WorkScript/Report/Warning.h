#pragma once
#include "ReportItem.h"

#define WS_WARNING_COMMON_DECL(CLASS_NAME) \
class CLASS_NAME : public WorkScriptWarning { public: using Warning::Warning; };

namespace WorkScript
{
    class Warning : public ReportItem
    {
    public:
        using ReportItem::ReportItem;
    };

}