#include <stdio.h>
#include <sstream>
#include "CmdArgs.h"
#include "ExternalCaller.h"
#include "Locales.h"
#include "Cleaner.h"
#include "Utils.h"
#include <unistd.h>
#include <dirent.h>

#include <llvm/Support/Host.h>
#include <llvm/ADT/Triple.h>

using namespace std;
using namespace WorkScript;

static std::wstring getExcutablePath()
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

static void sortStrReverse(std::vector<std::string> &strs)
{
    string temp;
    size_t len = strs.size();
    /*选择排序法*/
    for (size_t i=0; i<len; ++i)
        for (size_t j=i+1; j<len; ++j)
        {
            if (strcmp(strs[i].c_str(), strs[j].c_str()) < 0)
            {
                temp = strs[i];
                strs[i] = strs[j];
                strs[j] = temp;
            }
        }
}

static bool isVersionString(std::string str){
    enum {
        START, NUM, POINT, FAILURE
    } state = START;
    size_t i = 0, len = str.length();
    while(state != FAILURE && i < len) switch(state){
            case START:{
                if(isdigit(str[i])) state = NUM;
                else state = FAILURE;
                ++i;
                break;
            }
            case NUM:{
                if(isdigit(str[i])){ }
                else if(str[i] == '.') state = POINT;
                else state = FAILURE;
                ++i;
                break;
            }
            case POINT:{
                if(isdigit(str[i])) state = NUM;
                else state = FAILURE;
                ++i;
                break;
            }
            default: assert(0 && "unexcepted state");
        }
    return state == NUM;
}

static bool isDirEmpty(const std::string &path)
{
    /* 打开要进行匹配的文件目录 */
    DIR *dir = opendir(path.c_str());
    assert(dir && "无法打开目录");
    struct dirent *ent;
    bool found = false;
    while (ent = readdir(dir))
    {
        if (strcmp(".", ent->d_name) && strcmp("..", ent->d_name))
        {
            found = true;
        }
    }
    closedir(dir);
    return !found;
}

static std::string findGCCPath(const string &arch, const string &os, const string &env){
    string triple = arch + "-" + os + "-" + env;
    string pathPrefix = "/usr/lib/gcc/" + triple + "/";
    DIR *dir = opendir(pathPrefix.c_str());
    /*首先找出安装的gcc所有版本*/
    vector<string> versions;
    struct dirent *ent;
    while(ent = readdir(dir)){
        string version = ent->d_name;
        string curPath = pathPrefix + version;
        if(isVersionString(ent->d_name) && !isDirEmpty(curPath)){
            versions.push_back(version);
        }
    }
    closedir(dir);
    if(versions.size() == 0){
        fprintf(stderr, "%ls", L"未找到gcc安装路径\n");
        exit(1);
    }
    /*根据版本号倒序排列，找到最新版本的gcc*/
    sortStrReverse(versions);
    return pathPrefix + versions[0];
}

static void initLinkerCaller(const CmdArgs &args, const vector<wstring> &files, ExternalCaller *caller)
{
    llvm::Triple defaultTriple(llvm::sys::getDefaultTargetTriple());
    string arch = defaultTriple.getArchName();
    string os = defaultTriple.getOSName();
    string env = defaultTriple.getEnvironmentName();
    wstring triple = Locales::toWideChar(Encoding::ANSI, arch + "-" + os + "-" + env);
    caller->setProgram(L"ld");

    wstring gccPath = Locales::toWideChar(Encoding::ANSI, findGCCPath(arch, os, env));
    caller->addExtraArgBefore(L"-L" + gccPath);
    caller->addExtraArgBefore(L"--dynamic-linker=/lib64/ld-linux-x86-64.so.2");
    caller->addExtraArgBefore(L"-L/usr/lib/");
    caller->addExtraArgBefore(L"-L/usr/lib/" + triple + L"/");
    caller->addExtraArgBefore(L"/usr/lib/" + triple + L"/crt1.o");
    caller->addExtraArgBefore(L"/usr/lib/" + triple + L"/crti.o");
    for (const wstring &file : files)
    {
        caller->addExtraArgBefore(file);
    }
    caller->setArgs(args.getGroup(CmdArgGroup::LINKER));
    caller->addExtraArgAfter(L"/usr/lib/" + triple + L"/crtn.o");
    caller->addExtraArgAfter(L"--push-state --as-needed -lgcc_s --pop-state -lc -lgcc");
}

static void initWSCCaller(const CmdArgs &args, const vector<wstring> &files, const std::wstring &targetFile, ExternalCaller *caller){
    wstring path = getExcutablePath();
    wstring wscPath = path + L"/wsc";
    caller->setProgram(wscPath);
    for(auto &file : files){
        caller->addExtraArgBefore(file);
    }
    caller->addExtraArgAfter(L"-o " + targetFile);
    caller->setArgs(args.getGroup(CmdArgGroup::WSC));
}

static void initLLCCaller(const CmdArgs &args, const wstring &file, const std::wstring &targetFile, ExternalCaller *caller){
    caller->setProgram(L"llc");
    caller->addExtraArgBefore(file);
    caller->addExtraArgAfter(L"-o " + targetFile);
    caller->addExtraArgAfter(L"-filetype obj");
    caller->setArgs(args.getGroup(CmdArgGroup::LLC));
}

int main(int argc,const char **argv){
    CmdArgs args;
    CmdArgs::initArgs(&args);
    args.parse(argc, argv);

    Cleaner cleaner;
    cleaner.setCleanAtDestory(!args.get<bool>(L"save-temps"));

    vector<wstring> files = args.getRestArgs();
    if(files.size() != 1){
        fprintf(stderr, "%ls", L"请输入文件名！");
    }

    ExternalCaller wscCaller;
    initWSCCaller(args, files, L"a.ll", &wscCaller);
    cleaner.addFile(L"a.ll");
    if(wscCaller.call()) return 0;

    ExternalCaller llcCaller;
    initLLCCaller(args, L"a.ll", L"a.o", &llcCaller);
    cleaner.addFile(L"a.o");
    if(llcCaller.call()) return 0;

    ExternalCaller linkerCaller;
    initLinkerCaller(args, {L"a.o"}, &linkerCaller);
    if(linkerCaller.call()) return 0;
}