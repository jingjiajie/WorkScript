#ifndef CMDARG_H
#define CMDARG_H

#include <vector>
#include <unordered_map>
#include <string>
#include <type_traits>

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
        virtual void generate(cmdline::parser *parser) = 0;
        virtual void extract(cmdline::parser *parser) = 0;
        virtual bool belongsTo(CmdArgGroup group) const noexcept = 0;
        virtual std::wstring getName() const noexcept = 0;
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
                T defaultValue): groups(groups),
                name(name), shortName(shortName), description(desc),
                need(need), defaultValue(defaultValue) { }

        std::wstring getName() const noexcept{
            return this->name;
        }

        void generate(cmdline::parser *parser)
        {
            parser->add(Locales::fromWideChar(Encoding::ANSI, this->name), this->shortName,
                        Locales::fromWideChar(Encoding::ANSI, this->description), this->need, this->defaultValue);
        }

        typename std::enable_if<!std::is_same<T, bool>::value, void>::type
        extract(cmdline::parser *parser){
            this->value = parser->get<T>(Locales::fromWideChar(Encoding::ANSI, this->name));
        }

        typename std::enable_if<std::is_same<T, bool>::value, void>::type
        extract(cmdline::parser *parser){
            this->value = parser->exist(Locales::fromWideChar(Encoding::ANSI, this->name));
        }

        T getValue() const noexcept{return this->value;}

        bool belongsTo(CmdArgGroup group)const noexcept{
            for(size_t i=0; i<this->groups.size();++i){
                if(groups[i] == group) return true;
            }
            return false;
        }
    private:
        std::vector<CmdArgGroup> groups;
        std::wstring name;
        char shortName;
        std::wstring description;
        bool need = false;
        T defaultValue;
        T value;
    };

    class CmdArgs
    {
    public:
        ~CmdArgs(){
            for(auto item : this->args){
                delete item.second;
            }
        }

        void addCmdArg(CmdArgs *arg){
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

        std:vector<CmdArg*> getByGroup(CmdArgGroup group)
        {
            std::vector<CmdArg*> result;
            for(auto *item : this->args){
                if(item.second->belongsTo(group)) result.push_back(item.second);
            }
            return result;
        };
    private:
        std::unordered_map<std::wstring, CmdArg*> args;
    };

}

#endif //CMDARG_H
