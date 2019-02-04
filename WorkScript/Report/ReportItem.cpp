#include "Report.h"
#include <iomanip>
#include <sstream>

using namespace std;
using namespace WorkScript;

ReportItem::ReportItem(const WorkScript::DebugInfo &d, const std::wstring &wmsg)
        : debugInfo(d)
{
    wstringstream ss;
    ss << L"错误：" << d.getLocation().getFileName() << L" "
       << L"第" << setw(3) << to_wstring(d.getLocation().getLine()) << L"行，第"
       << setw(3) << to_wstring(d.getLocation().getColumn()) + L"列： "
       << wmsg;
    this->setMessage(ss.str());
}