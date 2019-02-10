#include "Report.h"
#include "Exception.h"
#include "Locales.h"
#include <string>
#include <sstream>

using namespace WorkScript;
using namespace std;

void Report::warning(const Warning &w)
{
    this->items.push_back(w);
}

void Report::error(const Error &e, ErrorBehavior behavior)
{
	this->error(e);
    switch(behavior) {
        case ErrorBehavior::CANCEL_EXPRESSION:
            throw ExpressionCanceledException();
        case ErrorBehavior::CANCEL_BLOCK:
            throw BlockCanceledException();
    }
}

void Report::error(const Error &e)
{
	items.push_back(e);
	++errorCount;
	if (errorCount >= maxErrorCount)
	{
		throw CompileTerminatedException(L"错误计数已达到" + to_wstring(this->errorCount) + L"，编译停止");
	}
}

void Report::dump() noexcept
{
    wstringstream ss;
    size_t itemCount = this->items.size();
    for (size_t i = 0; i < itemCount; ++i)
    {
        const ReportItem &e = this->items[i];
        ss << e.getMessage();
        if (i != itemCount - 1)
        {
            ss << std::endl;
        }
    }
    fprintf(stderr, "%ls", ss.str().c_str());
}
