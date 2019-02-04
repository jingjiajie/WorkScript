#pragma once
#include <vector>
#include "Error.h"
#include "Warning.h"

namespace WorkScript
{
    enum class ErrorBehavior{
        CONTINUE, CANCEL_EXPRESSION, CANCEL_BLOCK
    };

    class Report
    {
    public:
        inline explicit Report(size_t maxErrorCount = 20)
                : maxErrorCount(maxErrorCount)
        {}

        inline size_t getErrorCount() const
        { return this->errorCount; }

        void error(const Error &e, ErrorBehavior behavior);

        void warning(const Warning &w);

        void dump();

    private:
        std::vector<ReportItem> items;
        size_t errorCount = 0;
        size_t maxErrorCount;
    };
}