#ifndef CMDARG_H
#define CMDARG_H

#include <vector>
#include <unordered_map>
#include <string>
#include <type_traits>
#include <any>
#include <memory>

#include "cmdline.h"
#include "Locales.h"
#include "Exception.h"

namespace WorkScript
{
    enum class CmdArgGroup{
        WSC, LLC, LD
    };

    class CmdArg{
    public:
        virtual void generate(cmdline::parser *parser) const noexcept = 0;
        virtual void extract(cmdline::parser *parser) noexcept = 0;
        virtual std::any getValue() const noexcept = 0;

        std::wstring getName() const noexcept{
            return this->name;
        }

        bool belongsTo(CmdArgGroup group)const noexcept{
            for(size_t i=0; i<this->groups.size();++i){
                if(groups[i] == group) return true;
            }
            return false;
        }

    protected:
        CmdArg(
                const std::vector<CmdArgGroup> &groups,
                const std::wstring &name,
                char shortName,
                const std::wstring &desc,
                bool need): groups(groups),
                            name(name), shortName(shortName), description(desc),
                            need(need) { }

    protected:
        std::vector<CmdArgGroup> groups;
        std::wstring name;
        char shortName;
        std::wstring description;
        bool need = false;
    };

    template<typename T>
    class CmdArgSub : public CmdArg{
    public:
        CmdArgSub(
                const std::vector<CmdArgGroup> &groups,
                const std::wstring &name,
                char shortName,
                const std::wstring &desc,
                bool need,
                T defaultValue): CmdArg(groups, name, shortName, desc, need), defaultValue(defaultValue) { }

        void generate(cmdline::parser *parser) const noexcept override
        {
            parser->add<T>(Locales::fromWideChar(Encoding::ANSI, this->name), this->shortName,
                        Locales::fromWideChar(Encoding::ANSI, this->description), this->need, this->defaultValue);
        }

        void extract(cmdline::parser *parser) noexcept override{
            this->value = parser->get<T>(Locales::fromWideChar(Encoding::ANSI, this->name));
        }

        std::any getValue() const noexcept override{return this->value;}

    private:
        T defaultValue;
        T value;
    };

    class CmdArgs
    {
    public:
        CmdArgs() = default;

        explicit CmdArgs(const std::vector<std::shared_ptr<CmdArg>> &args){
            for(auto &arg : args){
                this->args[arg->getName()] = arg;
            }
        }

        void addStrArg(const std::vector<CmdArgGroup> &groups,
                       const std::wstring &name,
                       char shortName,
                       const std::wstring &desc,
                       bool need,
                       const wchar_t *defaultValue){
            if(this->args.find(name) != this->args.end()){
                throw InternalException(L"参数" + name + L"重复！");
            }
            std::shared_ptr<CmdArg> arg (new CmdArgSub<std::string>(groups, name, shortName, desc, need, Locales::fromWideChar(Encoding::ANSI,defaultValue)));
            this->args[arg->getName()] = arg;
        }

        void addBoolArg(const std::vector<CmdArgGroup> &groups,
                       const std::wstring &name,
                       char shortName,
                       const std::wstring &desc,
                       bool need,
                       bool defaultValue){
            if(this->args.find(name) != this->args.end()){
                throw InternalException(L"参数" + name + L"重复！");
            }
            std::shared_ptr<CmdArg> arg (new CmdArgSub<bool>(groups, name, shortName, desc, need, defaultValue));
            this->args[arg->getName()] = arg;
        }

        void addIntArg(const std::vector<CmdArgGroup> &groups,
                       const std::wstring &name,
                       char shortName,
                       const std::wstring &desc,
                       bool need,
                       int defaultValue){
            if(this->args.find(name) != this->args.end()){
                throw InternalException(L"参数" + name + L"重复！");
            }
            std::shared_ptr<CmdArg> arg (new CmdArgSub<int>(groups, name, shortName, desc, need, defaultValue));
            this->args[arg->getName()] = arg;
        }

        void parse(int argc, const char **argv)
        {
            cmdline::parser p;
            for(auto &item : this->args){
                item.second->generate(&p);
            }
            p.parse_check(argc, (char**)argv);
            for(auto &item : this->args){
                item.second->extract(&p);
            }
        }

        template<typename T>
        T get(const std::wstring &name) noexcept{
            auto it = this->args.find(name);
            if(it != this->args.end()){
                return std::any_cast<T>(it->second->getValue());
            }else{
                return T();
            }
        }

        CmdArgs getGroup(CmdArgGroup group)
        {
            std::vector<std::shared_ptr<CmdArg>> result;
            for(auto item : this->args){
                if(item.second->belongsTo(group)) result.push_back(item.second);
            }
            return CmdArgs(result);
        };
    private:
        std::unordered_map<std::wstring,std::shared_ptr<CmdArg>> args;
    };

}

#endif //CMDARG_H
