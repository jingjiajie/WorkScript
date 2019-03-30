#include <stdio.h>
#include <sstream>
#include "CmdArgs.h"
#include "ExternalCaller.h"
#include "Locales.h"
#include "Cleaner.h"
#include <unistd.h>

#include <llvm/Support/Host.h>
#include <llvm/ADT/Triple.h>

using namespace std;
using namespace WorkScript;

static void initLinkCaller(const CmdArgs &args, const vector<wstring> &files, ExternalCaller *caller){
    llvm::Triple defaultTriple(llvm::sys::getDefaultTargetTriple());
    string arch = defaultTriple.getArchName();
    string os = defaultTriple.getOSName();
    string env = defaultTriple.getEnvironmentName();

    caller->setProgram(L"ld");

    caller->addExtraArgBefore(L"--dynamic-linker=/lib64/ld-linux-x86-64.so.2");
    caller->addExtraArgBefore(L"-L/usr/lib/");
    caller->addExtraArgBefore(L"-L/usr/lib/x86_64-linux-gnu/");
    caller->addExtraArgBefore(L"/usr/lib/x86_64-linux-gnu/crt1.o");
    caller->addExtraArgBefore(L"/usr/lib/x86_64-linux-gnu/crti.o");
    for(const wstring &file : files){
        caller->addExtraArgBefore(file);
    }
    caller->setArgs(args.getGroup(CmdArgGroup::LINKER));
    caller->addExtraArgAfter(L"/usr/lib/x86_64-linux-gnu/crtn.o");
    caller->addExtraArgAfter(L"-lc");
}

static void initWSCCaller(const CmdArgs &args, const vector<wstring> &files, const std::wstring &targetFile, ExternalCaller *caller){
    //char *path = getcwd(nullptr, 0);
    //wstring wscPath = Locales::toWideChar(Encoding::ANSI, path) + L"/wsc";
    //delete path;
    caller->setProgram(L"./wsc");
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
    initLinkCaller(args, {L"a.o"}, &linkerCaller);

    if(linkerCaller.call()) return 0;
}