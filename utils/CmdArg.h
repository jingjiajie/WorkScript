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
                const std::wstring &desc,
                bool need): groups(groups),
                            name(name), description(desc),
                            need(need) { }

    protected:
        std::vector<CmdArgGroup> groups;
        std::wstring name;
        std::wstring description;
        bool need = false;
    };

    template<typename T>
    class CmdArgSub : public CmdArg{
    public:
        CmdArgSub(
                const std::vector<CmdArgGroup> &groups,
                const std::wstring &name,
                const std::wstring &desc,
                bool need,
                T defaultValue): CmdArg(groups, name, desc, need), defaultValue(defaultValue) { }

        void generate(cmdline::parser *parser) const noexcept override
        {
            parser->add<T>(Locales::fromWideChar(Encoding::ANSI, this->name), 'l',
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

        explicit CmdArgs(const std::vector<std::shared_ptr<CmdArg>> &args);

        void addStrArg(const std::vector<CmdArgGroup> &groups,
                       const std::wstring &name,
                       const std::wstring &desc,
                       bool need,
                       const wchar_t *defaultValue);

        void addBoolArg(const std::vector<CmdArgGroup> &groups,
                       const std::wstring &name,
                       const std::wstring &desc,
                       bool need,
                       bool defaultValue);

        void addIntArg(const std::vector<CmdArgGroup> &groups,
                       const std::wstring &name,
                       const std::wstring &desc,
                       bool need,
                       int defaultValue);

        void parse(int argc, const char **argv);

        template<typename T>
        T get(const std::wstring &name) noexcept{
            auto it = this->args.find(name);
            if(it != this->args.end()){
                return std::any_cast<T>(it->second->getValue());
            }else{
                return T();
            }
        }

        CmdArgs getGroup(CmdArgGroup group);
        std::wstring toString();
    private:
        std::unordered_map<std::wstring,std::shared_ptr<CmdArg>> args;
    };

}

#endif //CMDARG_H
