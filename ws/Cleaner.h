#pragma once
#include <string>
#include <vector>

namespace WorkScript
{
    class Cleaner
    {
    public:
        void addFile(const std::wstring &file) noexcept{
            this->files.push_back(file);
        }

        void setCleanAtDestory(bool clean) noexcept{ this->cleanAtDestory = clean;}

        ~Cleaner(){ if(this->cleanAtDestory) this->clean();}
        void clean();
    private:
        std::vector<std::wstring> files;
        bool cleanAtDestory = true;
    };

}