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
        virtual void extract(cmdline::parser *parser) const noexcept = 0;
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

    private:
        std::vector<CmdArgGroup> groups;
        std::wstring name;
        char shortName;
        std::wstring description;
        bool need = false;
    };

    template<typename T>
    class CmdArg : public CmdArg{
    public:
        CmdArg(
                const std::vector<CmdArgGroup> &groups,
                const std::wstring &name,
                char shortName,
                const std::wstring &desc,
                bool need,
                T defaultValue): CmdArgs(groups, name, shortName, desc, need), defaultValue(defaultValue) { }

        void generate(cmdline::parser *parser)const noexcept override
        {
            parser->add(Locales::fromWideChar(Encoding::ANSI, this->name), this->shortName,
                        Locales::fromWideChar(Encoding::ANSI, this->description), this->need, this->defaultValue);
        }

        typename std::enable_if<!std::is_same<T, bool>::value, void>::type
        extract(cmdline::parser *parser)const noexcept override{
            this->value = parser->get<T>(Locales::fromWideChar(Encoding::ANSI, this->name));
        }

        typename std::enable_if<std::is_same<T, bool>::value, void>::type
        extract(cmdline::parser *parser)const noexcept override{
            this->value = parser->exist(Locales::fromWideChar(Encoding::ANSI, this->name));
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

        void addCmdArg(std::shared_ptr<CmdArg> arg){
            if(this->args.find(arg->getName()) != this->args.end()){
                throw InternalException(L"参数" + arg->getName() + "重复！");
            }
            this->args[arg->getName()] = arg;
        }

        void parse(int argc, char **argv)
        {
            cmdline::parser p;
            for(auto &item : this->args){
                item.second->generate(p);
            }
            p.parse_check(argc, argv);
            for(auto &item : this->args){
                item.second->extract(p);
            }
        }

        std::shared_ptr<CmdArg> get(const std::wstring &name) noexcept{
            auto it = this->args.find(name);
            if(it != this->args.end()){
                return it->second;
            }else{
                return nullptr;
            }
        }

        CmdArgs getByGroup(CmdArgGroup group)
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
