#include "WorkScriptCompiler.h"
#include <Program.h>
#include <Expression.h>
#include <Report.h>
#include <Exception.h>
#include <Locales.h>
#include <FunctionFragment.h>
#include <memory>

using namespace std;
using namespace WorkScript;
using namespace llvm;


CompileResult WorkScriptCompiler::compile(const CmdArgs &args)
{
    auto files = args.getRestArgs();
    if(files.size() != 1){
        fprintf(stderr, "%ls", L"目前wsc仅支持一个.ws文件输入！");
        return CompileResult::ERROR;
    }
    LLVMContext llvmContext;

    Program program(Locales::fromWideChar(Encoding::ANSI, files[0]));
    auto llvmModule = unique_ptr<llvm::Module>(new llvm::Module("main", llvmContext));
    try {
        program.generateLLVMIR(&llvmContext, llvmModule.get());
    } catch (const CancelException &ex) {
        ex.rethrowAbove(CancelScope::COMPILATION);
    }
    Report *report = program.getReport();
    if (report->getErrorCount() > 0) {
        report->dump();
        return CompileResult::ERROR;
    }
    wstring targetFile = args.get<wstring>('o');
    std::error_code ec;
    llvm::raw_fd_ostream os(Locales::fromWideChar(Encoding::ANSI, targetFile), ec, llvm::sys::fs::OpenFlags::F_RW);
    llvmModule->print(os, nullptr);
    return CompileResult::OK;
}