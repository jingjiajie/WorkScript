#include <string>
#include <sstream>
#include <stdio.h>
#include "ExternalCaller.h"

using namespace std;
using namespace WorkScript;

std::wstring ExternalCaller::makeCmd()
{
    wstringstream cmd;
    cmd << this->program << L" ";
    for(wstring &arg : this->extraArgsBefore){
        cmd << arg << " ";
    }
    cmd << this->args.toString();
    for(wstring &arg : this->extraArgsAfter){
        cmd << arg << " ";
    }
    return cmd.str();
}

int ExternalCaller::call()
{
    string cmd = Locales::fromWideChar(Encoding::ANSI, this->makeCmd());
    //printf("%s\n", cmd.c_str());
    int rc = 0; // 用于接收命令返回值
    FILE *fp;

    fp = popen(cmd.c_str(), "r");
    if (nullptr == fp) {
        fprintf(stderr, "%ls\n", (L"无法执行" + this->program + L"，请检查环境配置").c_str());
        exit(1);
    }

    rc = pclose(fp);
    if (-1 == rc) {
        fprintf(stderr, "%ls\n", (this->program + L"关闭失败").c_str());
        exit(1);
    } else if(WEXITSTATUS(rc) != 0){
        fprintf(stderr, "%ls%u\n", (this->program + L"返回错误状态：").c_str(), WEXITSTATUS(rc));
    }
    return WEXITSTATUS(rc);
}