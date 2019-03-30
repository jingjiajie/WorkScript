#include "CmdArgs.h"
#include "string.h"
#include <assert.h>
#include <sstream>

using namespace std;
using namespace WorkScript;

CmdArg::CmdArg(WorkScript::CmdArgType type,const std::vector<WorkScript::CmdArgGroup> &groups,const std::wstring &name,
               unsigned char dashs, char shortName,const std::wstring &description, bool need) noexcept
    :type(type), groups(groups), name(name), dashs(dashs), shortName(shortName), description(description), need(need)
{

}

CmdArg::CmdArg(WorkScript::CmdArgType type,const std::vector<WorkScript::CmdArgGroup> &groups,const std::wstring &name,
               unsigned char dashs, char shortName,const std::wstring &description, bool need, const std::any &defaultValue) noexcept
    : CmdArg(type,groups,name,dashs,shortName,description,need)
{
    this->defaultValue = defaultValue;
}

void CmdArg::accept(const std::wstring &value)
{
    switch(this->type){
        case CmdArgType::BOOL:{
            this->value = true;
            break;
        }
        case CmdArgType::WSTRING:{
            this->value = value;
            break;
        }
        case CmdArgType::LONG:{
            for(size_t i=0; i<value.size(); ++i){
                if(value[i] < L'0' || value[i] > '9'){
                    fprintf(stderr, "%ls", (L"参数" + this->getNameStr() + L"必须为数字，接收到的值：" + value).c_str());
                    exit(1);
                }
            }
            long longval = 0;
            wstringstream ss;
            ss << value;
            ss >> longval;
            this->value = longval;
            break;
        }
        case CmdArgType::LIST:{
            auto &list = any_cast<vector<wstring>&>(this->value);
            list.push_back(value);
            break;
        }
    }
}

std::wstring CmdArg::getNameStr() const noexcept
{
    wstringstream ss;
    if(!this->name.empty()){
        for(size_t i=0; i<this->dashs; ++i){
            ss << L"-";
        }
        ss << this->name;
    }else{
        ss << L"-" << (wchar_t)this->shortName;
    }
    return ss.str();
}

CmdArgs::CmdArgs()
{
    memset(this->argIndexByShortName, 0, sizeof(this->argIndexByShortName));
}

CmdArgs::CmdArgs(const std::vector<CmdArg> &args)
: CmdArgs()
{
    this->args = args;
    for(size_t i=0; i<this->args.size(); ++i){
        this->makeIndex(&this->args[i], i);
    }
}

CmdArgs CmdArgs::getGroup(WorkScript::CmdArgGroup group) const noexcept
{
    std::vector<CmdArg> result;
    for (auto &arg : this->args)
    {
        for (size_t i = 0; i < arg.groups.size(); ++i) {
            if (arg.groups[i] == group) {
                result.push_back(arg);
                break;
            }
        }
    }
    return CmdArgs(result);
}

void CmdArgs::setStrArg(const std::vector<WorkScript::CmdArgGroup> &groups, const std::wstring &name,
                        unsigned char dashs,
                        char shortName,
                        const std::wstring &desc, bool need, const optional<const wchar_t *> &defaultValue)
{
    if(defaultValue.has_value()){
        this->setArg(
                CmdArg(CmdArgType::WSTRING, groups, name, dashs, shortName, desc, need, wstring(defaultValue.value())));
    }else{
        this->setArg(CmdArg(CmdArgType::WSTRING, groups, name, dashs, shortName, desc, need));
    }
}

void CmdArgs::setBoolArg(const std::vector<WorkScript::CmdArgGroup> &groups, const std::wstring &name,
                         unsigned char dashs,
                         char shortName,
                         const std::wstring &desc, bool need, const optional<bool> &defaultValue)
{
    if(defaultValue.has_value()){
        this->setArg(CmdArg(CmdArgType::BOOL, groups, name, dashs, shortName, desc, need, defaultValue.value()));
    }else{
        this->setArg(CmdArg(CmdArgType::BOOL, groups, name, dashs, shortName, desc, need));
    }
}

void CmdArgs::setLongArg(const std::vector<WorkScript::CmdArgGroup> &groups, const std::wstring &name,
                         unsigned char dashs,
                         char shortName,
                         const std::wstring &desc, bool need, const optional<long> &defaultValue)
{
    if(defaultValue.has_value()){
        this->setArg(CmdArg(CmdArgType::LONG, groups, name, dashs, shortName, desc, need, defaultValue.value()));
    }else{
        this->setArg(CmdArg(CmdArgType::LONG, groups, name, dashs, shortName, desc, need));
    }
}

void CmdArgs::setListArg(const std::vector<WorkScript::CmdArgGroup> &groups, const std::wstring &name,
                         unsigned char dashs, char shortName, const std::wstring &desc, bool need)
{
    CmdArg arg(CmdArgType::LIST, groups, name, dashs, shortName, desc, need);
    arg.value = vector<wstring>();
    this->setArg(arg);
}

void CmdArgs::setArg(const WorkScript::CmdArg &arg)
{
    this->args.push_back(arg);
    size_t index = this->args.size()-1;
    auto *pArg = &this->args[index];
    this->makeIndex(pArg, index);
}

void CmdArgs::setDefaultValue(char shortName, const std::any &value)
{
    CmdArg *arg = this->get(shortName);
    assert(arg && L"arg name not found!");
    arg->defaultValue = value;
}

void CmdArgs::setDefaultValue(const std::wstring &name, const std::any &value)
{
    CmdArg *arg = this->get(name);
    assert(arg && L"arg name not found!");
    arg->defaultValue = value;
}

CmdArg* CmdArgs::get(char shortName)
{
    CmdArg *arg = &this->args[this->argIndexByShortName[shortName]];
    return arg;
}

CmdArg* CmdArgs::get(const std::wstring &name)
{
    auto it = this->argIndexByName.find(name);
    if(it == this->argIndexByName.end())return nullptr;
    else return &this->args[it->second];
}

void CmdArgs::makeIndex(WorkScript::CmdArg *arg, size_t index)
{
    if(!arg->name.empty()){
        this->argIndexByName[arg->name] = index;
    }
    if(arg->shortName){
        this->argIndexByShortName[arg->shortName] = index;
    }
}

std::wstring CmdArgs::toString() const noexcept
{
    wstringstream ss;
    for(auto &arg : this->args){
        if(!arg.value.has_value()) {
            continue;
        }

        auto pushName = [&arg, &ss]{
            ss << arg.getNameStr() << L" ";
        };

        switch (arg.type){
            case CmdArgType::BOOL:{
                if(any_cast<bool>(arg.value)) pushName();
                break;
            }
            case CmdArgType::LONG:{
                pushName();
                ss << std::any_cast<long>(arg.value) << L" ";
                break;
            }
            case CmdArgType::WSTRING:{
                pushName();
                ss << std::any_cast<wstring>(arg.value) << L" ";
                break;
            }
            case CmdArgType::LIST:{
                auto list = any_cast<vector<wstring>>(arg.value);
                for(auto item : list){
                    pushName();
                    ss << item << L" ";
                }
            }
        }
    }
    for(auto &arg : this->restArgs){
        ss << arg << L" ";
    }
    return ss.str();
}

void CmdArgs::parse(int argc, const char **argv)
{
    enum {
        NORMAL ,NEED_VALUE
    } status = NORMAL;
    CmdArg *lastArg = nullptr;

    //循环遍历参数
    for(int i=1; i< argc; ++i){
        const char *cur = argv[i];
        wstring wcur = Locales::toWideChar(Encoding::ANSI, cur);
        size_t curLen = strlen(cur);
        //统计破折号数量
        int dashs = 0;
        for(size_t j=0; cur[j]; ++j){
            if(cur[j] == '-'){
                ++dashs;
            }else{
                break;
            }
        }
        const char *name = cur + dashs;
        wstring wname = Locales::toWideChar(Encoding::ANSI, name);
        switch(status) {
            case NORMAL: {
                //首先匹配参数全名
                auto it = this->argIndexByName.find(wname);
                if(it != this->argIndexByName.end()){
                    CmdArg *arg = &this->args[it->second];
                    if(arg->type == CmdArgType::BOOL){
                        arg->value = true;
                    }else{
                        lastArg = arg;
                        status = NEED_VALUE;
                    }
                }
                else if (dashs == 1) { //破折号只有1个，可能是short name
                    char shortName = name[0];
                    CmdArg *arg = &this->args[ this->argIndexByShortName[shortName]];
                    if (arg) {
                        if (name[1] != '\0') {
                            arg->accept(Locales::toWideChar(Encoding::ANSI, name + 1));
                        } else {
                            lastArg = arg;
                            status = NEED_VALUE;
                        }
                    }
                }else{ //如果既不是全名，也不是short name，则当做额外值
                    if(dashs > 0){
                        fprintf(stderr, "%ls", (L"无法识别的参数：" + wcur).c_str());
                        exit(1);
                    }else {
                        this->restArgs.push_back(wcur);
                    }
                }
                break;
            }
            case NEED_VALUE:{
                if(dashs > 0){
                    fprintf(stderr, "%ls", (lastArg->getNameStr() + L" 缺少值").c_str());
                    exit(1);
                }
                lastArg->accept(wcur);
                status = NORMAL;
                break;
            }
        }
    }
    //如果循环结束状态不为NORMAL，一定有错误
    if(status == NEED_VALUE){
        fprintf(stderr, "%ls", (lastArg->getNameStr() + L" 缺少值").c_str());
        exit(1);
    }

    //遍历参数，如果还有没有值的，取默认值。如果没有默认值，则报错
    for(auto &arg : this->args){
        if(!arg.need) continue;
        if(arg.type == CmdArgType::LIST){
            if(any_cast<vector<wstring>>(arg.value).empty()){
                if(arg.defaultValue.has_value()){
                    arg.value = arg.defaultValue;
                }else{
                    goto ERR;
                }
            }
        }else if(!arg.value.has_value()){
            if(arg.defaultValue.has_value()){
                arg.value = arg.defaultValue;
            }else{
                goto ERR;
            }
        }
        continue;
        ERR:
        fprintf(stderr, "%ls", (L"必须为参数 "+arg.getNameStr()+L" 指定一个值").c_str());
        exit(1);
    }
}

const std::vector<std::wstring>& CmdArgs::getRestArgs() const noexcept
{
    return this->restArgs;
}

void CmdArgs::initArgs(WorkScript::CmdArgs *__args)
{
#define BOOL_ARG(...) __args->setBoolArg(__VA_ARGS__);
#define LONG_ARG(...) __args->setLongArg(__VA_ARGS__);
#define STR_ARG(...)  __args->setStrArg(__VA_ARGS__);
#define LIST_ARG(...) __args->setListArg(__VA_ARGS__);

#include "CmdArgs.def"

#undef BOOL_ARG
#undef LONG_ARG
#undef STR_ARG
#undef LIST_ARG
}