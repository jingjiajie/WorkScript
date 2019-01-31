#pragma once
#include <vector>
#include "WorkScriptError.h"
#include "WorkScriptWarning.h"

namespace WorkScript
{
    enum class ErrorStatus{
        STOP, CONTINUE
    };

    class ErrorManager
    {
    public:
        static const size_t MAX_ERROR_COUNT = 20;

        static ErrorStatus error(const WorkScriptError &e);
        static ErrorStatus warning(const WorkScriptWarning &w);
    private:
        static std::vector<WorkScriptError> errors;
        static std::vector<WorkScriptWarning> warnings;
    };

}