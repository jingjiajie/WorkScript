#include <stdio.h>
#include <sstream>
#include "CmdArg.h"

using namespace std;
using namespace WorkScript;

static void initArgs(CmdArgs *args){
    args->addStrArg({CmdArgGroup::LLC}, L"", 0, 'o', L"target file", true, L"hehe");
    args->addListArg({CmdArgGroup::LD}, L"", 0, 'l', L"link libraries", false);
}

int main(int argc,const char **argv){
    CmdArgs args;
    initArgs(&args);
    args.parse(argc, argv);


//    int rc = 0; // 用于接收命令返回值
//    FILE *fp;
//
//    stringstream command;
//    command << "./wsc";
//
//
//    fp = popen(command.str().c_str(), "r");
//    if (nullptr == fp) {
//        fprintf(stderr, "%ls\n", L"无法执行ld，请检查环境配置");
//        exit(1);
//    }
//
//    rc = pclose(fp);
//    if (-1 == rc) {
//        fprintf(stderr, "%ls\n", L"ld关闭失败");
//        exit(1);
//    } else if(WEXITSTATUS(rc) != 0){
//        fprintf(stderr, "%ls%u\n", L"ld返回错误状态：", WEXITSTATUS(rc));
//    }
//
//    if(!SaveTemps) {
//        for (const auto &file : objFilePaths) {
//            remove(file.c_str());
//        }
//    }
}