//#ifdef __linux__
//#include "WorkScriptCompiler.h"
//#include <stdio.h>
//#include <string>
//#include <sstream>
//#include "Options.h"
//
//using namespace std;
//using namespace WorkScript;
//
//
//void WorkScriptCompiler::link(const std::vector<std::string> &objFilePaths)
//{
//    int rc = 0; // 用于接收命令返回值
//    FILE *fp;
//
//    stringstream command;
//    command << "ld --dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crtn.o /usr/lib/gcc/x86_64-linux-gnu/7/crtbegin.o /usr/lib/gcc/x86_64-linux-gnu/7/crtend.o -lc ";
//    for(const auto &objFile : objFilePaths){
//        command << objFile;
//    }
//    command << " -o " << OutputFilename;
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
//}
//
//#endif