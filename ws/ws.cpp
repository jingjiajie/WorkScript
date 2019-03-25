#include <stdio.h>
#include <sstream>
#include "CmdArg.h"
#include "LinkInfo.h"
#include "Locales.h"

#include <llvm/Support/Host.h>
#include <llvm/ADT/Triple.h>

using namespace std;
using namespace WorkScript;

static void initArgs(CmdArgs *args){
    args->addStrArg({CmdArgGroup::LLC}, L"", 0, 'o', L"target file", true, L"hehe");
    args->addStrArg({CmdArgGroup::LD}, L"march", 1, '\0', L"arch", false);
    args->addStrArg({CmdArgGroup::LD}, L"mtune", 1, '\0', L"tune", false);
    args->addListArg({CmdArgGroup::LD}, L"", 0, 'l', L"link libraries", false);
    args->addListArg({CmdArgGroup::LD}, L"", 0, 'L', L"link directories", false);
}

static void initLinkInfo(LinkInfo *info){
    llvm::Triple defaultTriple(llvm::sys::getDefaultTargetTriple());
    string arch = defaultTriple.getArchName();
    string os = defaultTriple.getOSName();
    string env = defaultTriple.getEnvironmentName();


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