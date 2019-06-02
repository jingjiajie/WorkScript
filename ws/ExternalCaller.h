#pragma once
#include <vector>
#include <string>
#include "CmdArgs.h"
#include "ExternalCaller.h"

namespace WorkScript
{
    class ExternalCaller
    {
    public:
        void setModule(const std::wstring &module){
            this->module = module;
        }

        void addExtraArgBefore(const std::wstring &arg) noexcept{
            this->extraArgsBefore.push_back(arg);
        }

        void addExtraArgAfter(const std::wstring &arg) noexcept{
            this->extraArgsAfter.push_back(arg);
        }

        void setArgs(const CmdArgs &args) noexcept{
            this->args = args;
        }

        CmdArgs& getArgs() noexcept{
            return this->args;
        }

        int call();
    private:
        std::wstring module;
        std::vector<std::wstring> extraArgsBefore;
        std::vector<std::wstring> extraArgsAfter;
        CmdArgs args;

        std::wstring makeCmd();
    };

}