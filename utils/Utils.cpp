#include "Utils.h"
#include "Locales.h"
#include <unistd.h>
#include <string.h>

using namespace std;
using namespace WorkScript;

std::wstring Utils::getExcutablePath()
{
    char path[512];
    auto ret = readlink("/proc/self/exe", path, 512);
    if(ret == -1){
        fprintf(stderr, "%ls%s", L"获取当前路径失败：", strerror(errno));
        exit(1);
    }
    char *pLastSlash = strrchr(path, '/');
    if(pLastSlash) *pLastSlash = '\0';
    wstring wpath = Locales::toWideChar(Encoding::ANSI, path);
    return wpath;
}