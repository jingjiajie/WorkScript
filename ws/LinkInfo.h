#pragma once
#include <vector>
#include <string>
#include "CmdArg.h"

namespace WorkScript
{
    class LinkInfo
    {
    public:
        void addObjFile(const std::wstring &file) noexcept{
            this->objFiles.push_back(file);
        }

        void addExtraLibPath(const std::wstring &path) noexcept{
            this->extraLibPaths.push_back(path):
        }

        void setLinkArgs(const CmdArgs &args) noexcept{
            this->linkArgs = args;
        }

        CmdArgs& getLinkArgs() noexcept{
            return this->linkArgs;
        }
    private:
        std::vector<std::wstring> objFiles;
        std::vector<std::wstring> extraLibPaths;
        CmdArgs linkArgs;
    };

}