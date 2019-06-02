#include "WorkScriptCompiler.h"
#include <Module.h>
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

    try {
        Module module;
        if(!module.load(Locales::fromWideChar(Encoding::ANSI, files[0]))){
            return CompileResult::ERROR;
        }
        Report *report = module.getReport();
        if (report->getErrorCount() > 0) {
            report->dump();
            return CompileResult::ERROR;
        }
        auto llvmModule = unique_ptr<llvm::Module>(new llvm::Module("main", llvmContext));
        module.generateLLVMIR(&llvmContext, llvmModule.get());
        if (report->getErrorCount() > 0) {
            report->dump();
            return CompileResult::ERROR;
        }
        wstring targetFile = args.get<wstring>('o');
        std::error_code ec;
        llvm::raw_fd_ostream os(Locales::fromWideChar(Encoding::ANSI, targetFile), ec, llvm::sys::fs::OpenFlags::F_RW);
        llvmModule->print(os, nullptr);
        return CompileResult::OK;
    } catch (const CancelException &ex) {
        ex.rethrowAbove(CancelScope::COMPILATION);
        return CompileResult::ERROR;
    }
}