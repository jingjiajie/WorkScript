#pragma once
#include "WorkScriptException.h"

#define WS_WARNING_COMMON_DECL(CLASS_NAME) \
class CLASS_NAME : public WorkScriptWarning { public: using WorkScriptWarning::WorkScriptWarning; };

namespace WorkScript{
    class WorkScriptWarning : public WorkScriptException
    {
    public:
        using WorkScriptException::WorkScriptException;
    };

}