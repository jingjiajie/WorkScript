#ifndef CMDARG_H
#define CMDARG_H

#include <vector>
#include <unordered_map>
#include <string>
#include <type_traits>
#include <any>
#include <memory>

#include "Locales.h"

namespace WorkScript
{
    enum class CmdArgGroup{
        WSC, LLC, LD
    };

    enum class CmdArgType{
        LONG, BOOL, WSTRING, LIST
    };

    struct CmdArg{
        CmdArg(CmdArgType type,
        const std::vector<CmdArgGroup> &groups,
        const std::wstring &name,
        unsigned char dashs,
        char shortName,
        const std::wstring &description,
        bool need,
        const std::any &defaultValue) noexcept;

        CmdArg(CmdArgType type,
               const std::vector<CmdArgGroup> &groups,
               const std::wstring &name,
               unsigned char dashs,
               char shortName,
               const std::wstring &description,
               bool need)noexcept;
        std::wstring getNameStr() const noexcept;
        void accept(const std::wstring &value);

        CmdArgType type;
        std::vector<CmdArgGroup> groups;
        std::wstring name;
        unsigned char dashs;
        char shortName;
        std::wstring description;
        bool need;
        std::any defaultValue;
        std::any value;
    };

    class CmdArgs
    {
    public:
        CmdArgs();

        explicit CmdArgs(const std::vector<CmdArg> &args);

        void addStrArg(const std::vector<CmdArgGroup> &groups,
                       const std::wstring &name,
                       unsigned char dashs,
                       char shortName,
                       const std::wstring &desc,
                       bool need,
                       const std::optional<const wchar_t *> &defaultValue = std::nullopt);

        void addBoolArg(const std::vector<CmdArgGroup> &groups,
                       const std::wstring &name,
                        unsigned char dashs,
                        char shortName,
                       const std::wstring &desc,
                       bool need,
                       const std::optional<bool> &defaultValue = std::nullopt);

        void addLongArg(const std::vector<CmdArgGroup> &groups,
                       const std::wstring &name,
                       unsigned char dashs,
                       char shortName,
                       const std::wstring &desc,
                       bool need,
                       const std::optional<long> &defaultValue = std::nullopt);

        void addListArg(const std::vector<CmdArgGroup> &groups,
                       const std::wstring &name,
                       unsigned char dashs,
                       char shortName,
                       const std::wstring &desc,
                       bool need);

        void parse(int argc, const char **argv);
        void setDefaultValue(const std::wstring &name, const std::any &value);
        void setDefaultValue(char shortName, const std::any &value);

        template<typename T>
        T get(const std::wstring &name) noexcept{
            auto it = this->argIndexByName.find(name);
            if(it != this->argIndexByName.end() && this->args[it->second].value.has_value()){
                return std::any_cast<T>(this->args[it->second].value);
            }else{
                return T();
            }
        }

        template<typename T>
        T get(char shortName) noexcept{
            CmdArg *arg = &this->args[this->argIndexByShortName[shortName]];
            if(arg && arg->value.has_value()){
                return std::any_cast<T>(arg->value);
            }else{
                return T();
            }
        }

        CmdArgs getGroup(CmdArgGroup group);
        std::wstring toString();
        const std::vector<std::wstring>& getRestArgs() const noexcept;
    private:
        std::vector<CmdArg> args;
        std::unordered_map<std::wstring,size_t> argIndexByName;
        size_t argIndexByShortName[256];
        std::vector<std::wstring> restArgs;

        void addArg(const CmdArg &arg);
        void makeIndex(CmdArg *arg, size_t index);
        CmdArg *get(const std::wstring &name);
        CmdArg *get(char shortName);
    };

}

#endif //CMDARG_H
