#include "CmdArg.h"
#include <sstream>

using namespace std;
using namespace WorkScript;

CmdArgs::CmdArgs(const std::vector<std::shared_ptr<WorkScript::CmdArg>> &args)
{
    for (auto &arg : args)
    {
        this->args[arg->getName()] = arg;
    }
}

CmdArgs CmdArgs::getGroup(WorkScript::CmdArgGroup group)
{
    std::vector<std::shared_ptr<CmdArg>> result;
    for (auto item : this->args)
    {
        if (item.second->belongsTo(group)) result.push_back(item.second);
    }
    return CmdArgs(result);
}

void CmdArgs::parse(int argc, const char **argv)
{
    cmdline::parser p;
    for (auto &item : this->args)
    {
        item.second->generate(&p);
    }
    p.parse_check(argc, (char **) argv);
    for (auto &item : this->args)
    {
        item.second->extract(&p);
    }
}

void CmdArgs::addStrArg(const std::vector<WorkScript::CmdArgGroup> &groups, const std::wstring &name,
                        const std::wstring &desc, bool need, const wchar_t *defaultValue)
{
    if (this->args.find(name) != this->args.end())
    {
        fprintf(stderr, "%ls", (L"参数" + name + L"重复！").c_str());
        exit(1);
    }
    std::shared_ptr<CmdArg> arg(new CmdArgSub<std::string>(groups, name, desc, need,
                                                           Locales::fromWideChar(Encoding::ANSI, defaultValue)));
    this->args[arg->getName()] = arg;
}

void CmdArgs::addBoolArg(const std::vector<WorkScript::CmdArgGroup> &groups, const std::wstring &name,
                         const std::wstring &desc, bool need, bool defaultValue)
{
    if (this->args.find(name) != this->args.end())
    {
        fprintf(stderr, "%ls", (L"参数" + name + L"重复！").c_str());
        exit(1);
    }
    std::shared_ptr<CmdArg> arg(new CmdArgSub<bool>(groups, name, desc, need, defaultValue));
    this->args[arg->getName()] = arg;
}

void CmdArgs::addIntArg(const std::vector<WorkScript::CmdArgGroup> &groups, const std::wstring &name,
                        const std::wstring &desc, bool need, int defaultValue)
{
    if (this->args.find(name) != this->args.end())
    {
        fprintf(stderr, "%ls", (L"参数" + name + L"重复！").c_str());
        exit(1);
    }
    std::shared_ptr<CmdArg> arg(new CmdArgSub<int>(groups, name, desc, need, defaultValue));
    this->args[arg->getName()] = arg;
}

std::wstring CmdArgs::toString()
{
//    wstringstream ss;
//    for(auto &item : this->args){
//        auto &arg = item.second;
//        ss << arg->getName()
//    }
}