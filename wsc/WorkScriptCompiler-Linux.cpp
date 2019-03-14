#ifdef __linux__
#include "WorkScriptCompiler.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include "Options.h"

using namespace std;
using namespace WorkScript;

#define MAXLINE 1024


void WorkScriptCompiler::link(const std::vector<std::string> &objFilePaths)
{
    int rc = 0; // 用于接收命令返回值
    FILE *fp;

    stringstream command;
    command << "ld --dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crtn.o /usr/lib/gcc/x86_64-linux-gnu/7/crtbegin.o /usr/lib/gcc/x86_64-linux-gnu/7/crtend.o -lc ";
    for(const auto &objFile : objFilePaths){
        command << objFile;
    }
    command << " -o " << OutputFilename;

    fp = popen(command.str().c_str(), "r");
    if (nullptr == fp) {
        fprintf(stderr, "%ls", L"无法执行ld，请检查环境配置\n");
        exit(1);
    }

    rc = pclose(fp);
    if (-1 == rc) {
        perror("关闭文件指针失败");
        exit(1);
    } else {
        printf("命令【%s】子进程结束状态【%d】命令返回值【%d】\r\n", command, rc, WEXITSTATUS(rc));
    }

}

#endif